/* Subroutines for RISC-V P (Packed SIMD) Extension for GNU compiler.
   Copyright (C) 2025 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "rtl.h"
#include "tree.h"
#include "memmodel.h"
#include "gimple.h"
#include "tm_p.h"
#include "optabs.h"
#include "recog.h"
#include "diagnostic-core.h"
#include "expr.h"
#include "explow.h"
#include "insn-config.h"
#include "insn-attr.h"
#include "emit-rtl.h"
#include "optabs-tree.h"

/* Expand RVP vector comparison.
   Implements vec_cmp<mode><mode> and vec_cmpu<mode><mode> patterns.  */
void
riscv_p_expand_vec_cmp (rtx *operands)
{
  enum rtx_code code = GET_CODE (operands[1]);
  rtx result = operands[0];
  rtx op1 = operands[2];
  rtx op2 = operands[3];
  machine_mode mode = GET_MODE (result);
  rtx tmp;

  switch (code)
    {
    case EQ:
      emit_move_insn (result, gen_rtx_EQ (mode, op1, op2));
      break;

    case NE:
      /* result = ~(op1 == op2) */
      tmp = gen_reg_rtx (mode);
      emit_move_insn (tmp, gen_rtx_EQ (mode, op1, op2));
      emit_insn (gen_rtx_SET (result, gen_rtx_NOT (mode, tmp)));
      break;

    case LT:
    case LTU:
      emit_move_insn (result, gen_rtx_fmt_ee (code, mode, op1, op2));
      break;

    case LE:
    case LEU:
      {
	/* result = ~(op2 < op1) */
	enum rtx_code base_code = (code == LE) ? LT : LTU;
	tmp = gen_reg_rtx (mode);
	emit_move_insn (tmp, gen_rtx_fmt_ee (base_code, mode, op2, op1));
	emit_insn (gen_rtx_SET (result, gen_rtx_NOT (mode, tmp)));
      }
      break;

    case GT:
    case GTU:
      {
	/* result = (op2 < op1) */
	enum rtx_code base_code = (code == GT) ? LT : LTU;
	emit_move_insn (result, gen_rtx_fmt_ee (base_code, mode, op2, op1));
      }
      break;

    case GE:
    case GEU:
      {
	/* result = ~(op1 < op2) */
	enum rtx_code base_code = (code == GE) ? LT : LTU;
	tmp = gen_reg_rtx (mode);
	emit_move_insn (tmp, gen_rtx_fmt_ee (base_code, mode, op1, op2));
	emit_insn (gen_rtx_SET (result, gen_rtx_NOT (mode, tmp)));
      }
      break;

    default:
      gcc_unreachable ();
    }
}

/* Expand RVP vector conditional mask operation.
   Implements vcond_mask_<mode><mode> pattern.

   Implements: result = mask ? op1 : op2
   For each element i: result[i] = mask[i] ? op1[i] : op2[i]

   Optimizations:
   1. If (op1 == -1 && op2 == 0): result = mask
   2. If (op1 == 0 && op2 == -1): result = ~mask
   3. General case: result = (mask & op1) | (~mask & op2)  */
void
riscv_p_expand_vcond_mask (rtx *operands)
{
  rtx result = operands[0];
  rtx op1 = operands[1];
  rtx op2 = operands[2];
  rtx mask = operands[3];
  machine_mode mode = GET_MODE (result);

  /* Optimize: mask ? -1 : 0 -> mask */
  if (op1 == CONSTM1_RTX (mode) && op2 == CONST0_RTX (mode))
    {
      emit_move_insn (result, mask);
      return;
    }

  /* Optimize: mask ? 0 : -1 -> ~mask */
  if (op1 == CONST0_RTX (mode) && op2 == CONSTM1_RTX (mode))
    {
      emit_insn (gen_rtx_SET (result, gen_rtx_NOT (mode, mask)));
      return;
    }

  /* GENERAL CASE: result = (mask & op1) | (~mask & op2)
     Use vector bitwise operations directly.  */

  /* Handle constant operands - copy them into registers.  */
  if (CONST_VECTOR_P (op1))
    op1 = force_reg (mode, op1);
  if (CONST_VECTOR_P (op2))
    op2 = force_reg (mode, op2);

  rtx not_mask = gen_reg_rtx (mode);
  rtx tmp1 = gen_reg_rtx (mode);
  rtx tmp2 = gen_reg_rtx (mode);

  /* not_mask = ~mask */
  emit_insn (gen_rtx_SET (not_mask, gen_rtx_NOT (mode, mask)));

  /* tmp1 = mask & op1 */
  emit_insn (gen_rtx_SET (tmp1, gen_rtx_AND (mode, mask, op1)));

  /* tmp2 = ~mask & op2 */
  emit_insn (gen_rtx_SET (tmp2, gen_rtx_AND (mode, not_mask, op2)));

  /* result = tmp1 | tmp2 */
  emit_insn (gen_rtx_SET (result, gen_rtx_IOR (mode, tmp1, tmp2)));
}
