/* Branch Target Identification for RISCV architecture.
   Copyright (C) 2019-2025 Free Software Foundation, Inc.
   Based on ARM target.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#define INCLUDE_STRING
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "tree.h"
#include "memmodel.h"
#include "gimple.h"
#include "tm_p.h"
#include "stringpool.h"
#include "attribs.h"
#include "expr.h"
#include "emit-rtl.h"
#include "gimplify.h"
#include "gimple-iterator.h"
#include "dumpfile.h"
#include "rtl-iter.h"
#include "cfgrtl.h"
#include "tree-pass.h"
#include "cgraph.h"
#include "output.h"
#include "insn-opinit.h"

/* This pass implements forward-CFI landing pad checks for RISCV. This is
   a security feature similar to BTI (branch target identification) in
   AArch64 and IBT (indirect branch tracking)in X86. A LPAD (landing-pad
   check) instruction is used to guard against the execution of
   instructions which are not the intended target of an indirect branch.

   When forward-CFI is disabled or unimplemented in the CPU, the
   landing-pad check label instructions behave as NOP. When implemented in
   the CPU, and enabled, the destination of an indirect branch must be
   LPAD insn. Otherwise, the CPU reaises an exception.

   In order to enable this mechanism, this pass iterates through the
   control flow of the code and adds appropriate LPAD instructions at the
   beginning of any function that can be called indirectly, and for targets
   of indirect jumps, i.e., jump table targets, non-local goto targets, and
   labels that might be referenced by variables, constant pools, etc
   (NOTE_INSN_DELETED_LABEL). */

namespace {

const pass_data pass_data_insert_landing_pad =
{
  RTL_PASS, /* type. */
  "zisslpcfi", /* name. */
  OPTGROUP_NONE, /* optinfo_flags. */
  TV_MACH_DEP, /* tv_id. */
  0, /* properties_required. */
  0, /* properties_provided. */
  0, /* properties_destroyed. */
  0, /* todo_flags_start. */
  0, /* todo_flags_finish. */
};

static bool
is_interrupt_handler_p (tree type)
{
  return lookup_attribute ("interrupt", TYPE_ATTRIBUTES (type)) != NULL;
}

/* Check if the called function has an indirect_return attribute.
   Functions marked with this attribute may return indirectly and require
   LPAD protection after calls to them.  */
static bool
riscv_fun_is_indirect_return (rtx_insn *insn)
{
  /* Extract the function being called from the call instruction.
     Since CALL_P (insn) was already checked, we know this is a CALL_INSN.  */
  rtx call_rtx = PATTERN (insn);

  if (GET_CODE (call_rtx) == PARALLEL)
    call_rtx = XVECEXP (call_rtx, 0, 0);

  if (GET_CODE (call_rtx) == SET)
    call_rtx = SET_SRC (call_rtx);

  gcc_assert (GET_CODE (call_rtx) == CALL);

  rtx fn = XEXP (call_rtx, 0);
  if (GET_CODE (fn) != MEM)
    return false;

  rtx addr = XEXP (fn, 0);
  if (GET_CODE (addr) != SYMBOL_REF)
    return false;

  /* Get the function declaration from the symbol reference.  */
  tree decl = SYMBOL_REF_DECL (addr);
  if (!decl || TREE_CODE (decl) != FUNCTION_DECL)
    return false;

  /* Check for the indirect_return attribute on the function type.  */
  tree fntype = TREE_TYPE (decl);
  return lookup_attribute ("indirect_return", TYPE_ATTRIBUTES (fntype)) != NULL;
}

/* Decide if LPAD is needed after a call instruction.
   LPAD is required for calls that may return indirectly to provide
   control flow integrity protection.  */
static bool
call_needs_lpad (rtx_insn *insn)
{
  /* Call returns twice, one of which may be indirect (e.g., setjmp).  */
  if (find_reg_note (insn, REG_SETJMP, NULL))
    return true;

  /* Tail call does not return to the call site.  */
  if (SIBLING_CALL_P (insn))
    return false;

  /* Check if the function is marked to return indirectly.  */
  return riscv_fun_is_indirect_return (insn);
}

/* Insert landing-pad check instructions.  This is a late RTL pass that runs
   before branch shortening. */
static unsigned int
rest_of_insert_landing_pad (void)
{
  timevar_push (TV_MACH_DEP);

  struct cgraph_node *c_node;
  rtx lpad_insn;
  rtx_insn *insn;
  basic_block bb;
  rtx lp_value = riscv_get_lp_value (cfun->decl);

  int attribute_lp_value = riscv_attribute_get_lp_value (cfun->decl);
  if (attribute_lp_value != -1)
    lp_value = GEN_INT (attribute_lp_value);

  bb = 0;
  FOR_EACH_BB_FN (bb, cfun)
    {
      for (insn = BB_HEAD (bb); insn != NEXT_INSN (BB_END (bb));
	   insn = NEXT_INSN (insn))
	{
	  /* If a label is marked to be preserved or can be a non-local goto
	     target, it must be protected with a lpad instruction.
	     Insert .align 2 after label, then lpad, to ensure 4-byte alignment.  */
	  if (LABEL_P (insn)
	       && (LABEL_PRESERVE_P (insn)
		   || bb->flags & BB_NON_LOCAL_GOTO_TARGET))
	    {
	      rtx_insn *align_insn = emit_insn_after (gen_lpad_align (), insn);
	      emit_insn_after (gen_lpad (lp_value), align_insn);
	      continue;
	    }

	  /* gpr_save generates "call t0, __riscv_save_N" which returns to
	     the next instruction (lpad).  When Zca/RVC is enabled, linker
	     relaxation can convert this call to compressed form, causing
	     the return address to be misaligned.  Use .option norelax to
	     prevent this.

	     We insert .p2align 2 before the call to ensure alignment when
	     linker relaxes preceding instructions.  When Zca is enabled,
	     we also add .option norelax to prevent call relaxation.  */
	  if (INSN_P (insn) && INSN_CODE (insn) == CODE_FOR_gpr_save)
	    {
	      emit_insn (gen_set_lpl (Pmode, lp_value));
	      if (TARGET_ZCA)
		{
		  emit_insn_before (gen_lpad_align_norelax (), insn);
		  rtx_insn *lpad_insn
		    = emit_insn_after (gen_lpad (lp_value), insn);
		  emit_insn_after (gen_option_pop (), lpad_insn);
		}
	      else
		{
		  emit_insn_before (gen_lpad_align (), insn);
		  emit_insn_after (gen_lpad (lp_value), insn);
		}
	      continue;
	    }

	  if (INSN_P (insn) && INSN_CODE (insn) == CODE_FOR_gpr_restore)
	    emit_insn (gen_set_lpl (Pmode, lp_value));

	  /* Check for calls that may return indirectly, such as setjmp
	     or functions marked with indirect_return attribute,
	     and insert LPAD after them for control flow protection.
	     Use lpad 0 (unlabeled) since longjmp can return from anywhere.

	     When Zca is enabled, linker relaxation can convert calls to
	     compressed forms (c.jal on RV32, cm.jalt with Zcmt), which would
	     cause LPAD misalignment. To prevent this:
	       .p2align 2
	       .option push
	       .option norelax
	       call foo
	       .option pop
	       lpad 0

	     The .p2align 2 generates R_RISCV_ALIGN relocation so the linker
	     maintains alignment when relaxing preceding instructions.
	     The .option norelax prevents call relaxation to compressed forms.

	     When Zca is not enabled, calls cannot be relaxed to compressed
	     forms, but we still need .p2align 2 to ensure lpad alignment when
	     linker relaxes preceding instructions.  */
	  if (CALL_P (insn) && call_needs_lpad (insn))
	    {
	      if (TARGET_ZCA)
		{
		  emit_insn_before (gen_lpad_align_norelax (), insn);
		  rtx_insn *pop_insn = emit_insn_after (gen_option_pop (), insn);
		  emit_insn_after (gen_lpad (const0_rtx), pop_insn);
		}
	      else
		{
		  emit_insn_before (gen_lpad_align (), insn);
		  emit_insn_after (gen_lpad (const0_rtx), insn);
		}
	      continue;
	    }
	}
    }

  c_node = cgraph_node::get (cfun->decl);
  if (!c_node->only_called_directly_p ()
      && !is_interrupt_handler_p (TREE_TYPE (cfun->decl))
      && !flag_gimple)
    {
      bb = ENTRY_BLOCK_PTR_FOR_FN (cfun)->next_bb;
      insn = BB_HEAD (bb);
      /* Function entry is already 4-byte aligned by the function label,
	 so we don't need to insert .p2align 2 here.  */
      lpad_insn = gen_lpad (lp_value);
      emit_insn_before (lpad_insn, insn);
    }

  timevar_pop (TV_MACH_DEP);
  return 0;
}

class pass_insert_landing_pad : public rtl_opt_pass
{
public:
  pass_insert_landing_pad (gcc::context *ctxt)
    : rtl_opt_pass (pass_data_insert_landing_pad, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *)
    {
      return is_zicfilp_p ();
    }

  virtual unsigned int execute (function *)
    {
      return rest_of_insert_landing_pad ();
    }

}; // class pass_insert_landing_pad

} // anon namespace

rtl_opt_pass *
make_pass_insert_landing_pad (gcc::context *ctxt)
{
  return new pass_insert_landing_pad (ctxt);
}
