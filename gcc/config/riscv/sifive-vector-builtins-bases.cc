/* function_base implementation for SiFive custom 'V' Extension for GNU compiler.
   Copyright (C) 2024 Free Software Foundation, Inc.
   Contributed by SiFive.

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

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "memmodel.h"
#include "insn-codes.h"
#include "optabs.h"
#include "recog.h"
#include "expr.h"
#include "basic-block.h"
#include "function.h"
#include "fold-const.h"
#include "gimple.h"
#include "gimple-iterator.h"
#include "gimplify.h"
#include "explow.h"
#include "emit-rtl.h"
#include "tree-vector-builder.h"
#include "rtx-vector-builder.h"
#include "riscv-vector-builtins.h"
#include "riscv-vector-builtins-shapes.h"
#include "sifive-vector-builtins-bases.h"

using namespace riscv_vector;

namespace riscv_vector {

/* Implements SiFive vqmacc.  */
class sf_vqmacc : public function_base
{
public:
  bool has_merge_operand_p () const override { return false; }
  bool apply_mask_policy_p () const override { return false; }
  bool use_mask_predication_p () const override { return false; }
  bool can_be_overloaded_p (enum predication_type_index pred) const override
  {
    return pred == PRED_TYPE_tu;
  }

  rtx expand (function_expander &e) const override
  {
    if (e.op_info->op == OP_TYPE_4x8x4)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plus_qoq (SIGN_EXTEND, e.vector_mode ()));
    if (e.op_info->op == OP_TYPE_2x8x2)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plus_dod (SIGN_EXTEND, e.vector_mode ()));
    gcc_unreachable ();
  }
};

/* Implements SiFive vqmaccu.  */
class sf_vqmaccu : public function_base
{
public:
  bool has_merge_operand_p () const override { return false; }
  bool apply_mask_policy_p () const override { return false; }
  bool use_mask_predication_p () const override { return false; }

  bool can_be_overloaded_p (enum predication_type_index pred) const override
  {
    return pred == PRED_TYPE_tu;
  }

  rtx expand (function_expander &e) const override
  {
    if (e.op_info->op == OP_TYPE_4x8x4)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plus_qoq (ZERO_EXTEND, e.vector_mode ()));
    if (e.op_info->op == OP_TYPE_2x8x2)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plus_dod (ZERO_EXTEND, e.vector_mode ()));
    gcc_unreachable ();
  }
};

/* Implements SiFive vqmaccsu.  */
class sf_vqmaccsu : public function_base
{
public:
  bool has_merge_operand_p () const override { return false; }
  bool apply_mask_policy_p () const override { return false; }
  bool use_mask_predication_p () const override { return false; }

  bool can_be_overloaded_p (enum predication_type_index pred) const override
  {
    return pred == PRED_TYPE_tu;
  }

  rtx expand (function_expander &e) const override
  {
    if (e.op_info->op == OP_TYPE_4x8x4)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plussu_qoq (e.vector_mode ()));
    if (e.op_info->op == OP_TYPE_2x8x2)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plussu_dod (e.vector_mode ()));
    gcc_unreachable ();
  }
};

/* Implements SiFive vqmaccus.  */
class sf_vqmaccus : public function_base
{
public:
  bool has_merge_operand_p () const override { return false; }
  bool apply_mask_policy_p () const override { return false; }
  bool use_mask_predication_p () const override { return false; }

  bool can_be_overloaded_p (enum predication_type_index pred) const override
  {
    return pred == PRED_TYPE_tu;
  }

  rtx expand (function_expander &e) const override
  {
    if (e.op_info->op == OP_TYPE_4x8x4)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plusus_qoq (e.vector_mode ()));
    if (e.op_info->op == OP_TYPE_2x8x2)
      return e.use_widen_ternop_insn (
	code_for_pred_matrix_mul_plusus_dod (e.vector_mode ()));
    gcc_unreachable ();
  }
};

static CONSTEXPR const sf_vqmacc sf_vqmacc_obj;
static CONSTEXPR const sf_vqmaccu sf_vqmaccu_obj;
static CONSTEXPR const sf_vqmaccsu sf_vqmaccsu_obj;
static CONSTEXPR const sf_vqmaccus sf_vqmaccus_obj;

/* Declare the function base NAME, pointing it to an instance
   of class <NAME>_obj.  */
#define BASE(NAME) \
  namespace bases { const function_base *const NAME = &NAME##_obj; }

BASE (sf_vqmacc)
BASE (sf_vqmaccu)
BASE (sf_vqmaccsu)
BASE (sf_vqmaccus)
} // end namespace riscv_vector
