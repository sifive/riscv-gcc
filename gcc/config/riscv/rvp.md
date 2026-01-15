;; Machine description for RISC-V Packed (RVP) extension
;; Copyright (C) 2025 Free Software Foundation, Inc.

;; This file is part of GCC.

;; GCC is free software; you can redistribute it and/or modify
;; it under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.

;; GCC is distributed in the hope that it will be useful,
;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;; GNU General Public License for more details.

;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

(include "rvp-iterators.md")

;; Move pattern for PVQIHI modes (byte and halfword packed vectors)
(define_expand "mov<mode>"
  [(set (match_operand:PVQIHI 0 "")
	(match_operand:PVQIHI 1 ""))]
  "TARGET_RVP"
{
  if (riscv_legitimize_move (<MODE>mode, operands[0], operands[1]))
    DONE;
})

;; Internal move pattern for PVQIHI modes
(define_insn "*mov<mode>_internal"
  [(set (match_operand:PVQIHI 0 "nonimmediate_operand" "=r,r,r, m,  *f,*f,*r,*m")
	(match_operand:PVQIHI 1 "move_operand"         " r,T,m,rJ,*r*J,*m,*f,*f"))]
  "(register_operand (operands[0], <MODE>mode)
    || reg_or_0_operand (operands[1], <MODE>mode))
   && TARGET_RVP"
  { return riscv_output_move (operands[0], operands[1]); }
  [(set_attr "move_type" "move,const,load,store,mtc,fpload,mfc,fpstore")
   (set_attr "type" "move,move,load,store,mtc,fpload,mfc,fpstore")
   (set_attr "mode" "<MODE>")])

;; Move pattern for PV2SI mode (2×32-bit packed vector, RV64 only)
(define_expand "movpv2si"
  [(set (match_operand:PV2SI 0 "")
	(match_operand:PV2SI 1 ""))]
  "TARGET_64BIT && TARGET_RVP"
{
  if (riscv_legitimize_move (PV2SImode, operands[0], operands[1]))
    DONE;
})

;; Internal move pattern for PV2SI mode
(define_insn "*movpv2si_64bit"
  [(set (match_operand:PV2SI 0 "nonimmediate_operand" "=r,r,r, m,  *f,*f,*r,*f,*m")
	(match_operand:PV2SI 1 "move_operand"         " r,T,m,rJ,*r*J,*m,*f,*f,*f"))]
  "TARGET_64BIT && TARGET_RVP
   && (register_operand (operands[0], PV2SImode)
       || reg_or_0_operand (operands[1], PV2SImode))"
  { return riscv_output_move (operands[0], operands[1]); }
  [(set_attr "move_type" "move,const,load,store,mtc,fpload,mfc,fmove,fpstore")
   (set_attr "type" "move,move,load,store,mtc,fpload,mfc,fmove,fpstore")
   (set_attr "mode" "PV2SI")])

;; Binary Arithmetic Operations

;; Unified pattern for all binary arithmetic operations
;;   - Basic: padd.b/h/w, psub.b/h/w
;;   - Saturating signed: psadd.b/h/w, pssub.b/h/w
;;   - Saturating unsigned: psaddu.b/h/w, pssubu.b/h/w
;;   - Min/max signed: pmin.b/h/w, pmax.b/h/w
;;   - Min/max unsigned: pminu.b/h/w, pmaxu.b/h/w
(define_insn "<rvp_optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(rvp_binop:PVALL (match_operand:PVALL 1 "register_operand" "r")
			 (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "<rvp_insn>.<rvp_width>\t%0, %1, %2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Vector shift instructions by scalar amount (operand 2 is scalar SI)
(define_insn "<rvp_shift_optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r, r")
        (shift_op:PVALL
          (match_operand:PVALL 1 "register_operand" "r, r")
          (match_operand:SI 2 "reg_or_int_operand" "r, I")))]
  "TARGET_RVP"
  "@
   <rvp_shift_insn>.<rvp_width>s\t%0,%1,%2
   <rvp_shift_insn>i.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "shift")
   (set_attr "mode" "<MODE>")])

;; Signed packed multiply high for all packed element sizes (bytes/halfwords/words)
(define_insn "smul<mode>3_highpart"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
        (smul_highpart:PVALL
          (match_operand:PVALL 1 "register_operand" "r")
          (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "pmulh.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Unsigned packed multiply high for all packed element sizes (bytes/halfwords/words)
(define_insn "umul<mode>3_highpart"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
        (umul_highpart:PVALL
          (match_operand:PVALL 1 "register_operand" "r")
          (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "pmulhu.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Averaging arithmetic operations
;; paadd/paaddu: signed/unsigned averaging add: (a + b) >> 1
;; pasub/pasubu: signed/unsigned averaging subtract: (a - b) >> 1

;; Signed averaging
(define_insn "<avg_insn><mode>"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(ashiftrt:PVALL
	  (avg_op:PVALL (match_operand:PVALL 1 "register_operand" "r")
			(match_operand:PVALL 2 "register_operand" "r"))
	  (const_int 1)))]
  "TARGET_RVP"
  "<avg_insn>.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Unsigned averaging
(define_insn "<avg_insn>u<mode>"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(lshiftrt:PVALL
	  (avg_op:PVALL (match_operand:PVALL 1 "register_operand" "r")
			(match_operand:PVALL 2 "register_operand" "r"))
	  (const_int 1)))]
  "TARGET_RVP"
  "<avg_insn>u.<rvp_width>\t%0,%1,%2"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Vector comparison expander for signed comparisons
(define_expand "vec_cmp<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(match_operator:PVALL 1 "comparison_operator"
	  [(match_operand:PVALL 2 "register_operand")
	   (match_operand:PVALL 3 "register_operand")]))]
  "TARGET_RVP"
{
  riscv_p_expand_vec_cmp (operands);
  DONE;
})

;; Vector comparison expander for unsigned comparisons
(define_expand "vec_cmpu<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(match_operator:PVALL 1 "comparison_operator"
	  [(match_operand:PVALL 2 "register_operand")
	   (match_operand:PVALL 3 "register_operand")]))]
  "TARGET_RVP"
{
  riscv_p_expand_vec_cmp (operands);
  DONE;
})

;; Vector conditional mask operation
;; Implements: result = mask ? op1 : op2
;; For each element i: result[i] = mask[i] ? op1[i] : op2[i]
(define_expand "vcond_mask_<mode><mode>"
  [(set (match_operand:PVALL 0 "register_operand")
	(if_then_else:PVALL
	  (match_operand:PVALL 3 "register_operand")
	  (match_operand:PVALL 1 "nonmemory_operand")
	  (match_operand:PVALL 2 "nonmemory_operand")))]
  "TARGET_RVP"
{
  riscv_p_expand_vcond_mask (operands);
  DONE;
})

;; Bitwise operations for vector modes
(define_insn "<optab><mode>3"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(any_bitwise:PVALL (match_operand:PVALL 1 "register_operand" "r")
			   (match_operand:PVALL 2 "register_operand" "r")))]
  "TARGET_RVP"
  "<insn>\t%0,%1,%2"
  [(set_attr "type" "logical")
   (set_attr "mode" "DI")])

(define_insn "one_cmpl<mode>2"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(not:PVALL (match_operand:PVALL 1 "register_operand" "r")))]
  "TARGET_RVP"
  "not\t%0,%1"
  [(set_attr "type" "logical")
   (set_attr "mode" "DI")])

;; ============================================================================
;; PLI/PLUI: Packed Load Immediate Instructions
;; ============================================================================
;;
;; PLI.B rd, imm8   - Broadcast 8-bit value to all bytes
;; PLI.H rd, imm10  - Broadcast 10-bit signed value to all halfwords
;; PLI.W rd, imm10  - Broadcast 10-bit signed value to all words (RV64)
;; PLUI.H rd, imm10 - Broadcast (imm10 << 6) to all halfwords
;; PLUI.W rd, imm10 - Broadcast (imm10 << 22) to all words (RV64)
;;
;; These patterns are handled by riscv_output_move via riscv_output_pli.

;; vec_duplicate patterns for PLI.B/PLI.H/PLI.W
(define_insn "*riscv_pli_vec"
  [(set (match_operand:PVALL 0 "register_operand" "=r")
	(vec_duplicate:PVALL
	  (match_operand:<PVALL_ELT> 1 "const_int_operand" "<dpli>")))]
  "TARGET_RVP"
  "pli.<rvp_width>\t%0,%1"
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; vec_duplicate patterns for PLUI.H/PLUI.W
(define_insn "*riscv_plui_vec"
  [(set (match_operand:PVPLUI 0 "register_operand" "=r")
	(vec_duplicate:PVPLUI
	  (match_operand:<PVALL_ELT> 1 "const_int_operand" "<dplui>")))]
  "TARGET_RVP"
  {
    operands[2] = GEN_INT (INTVAL (operands[1]) >> <plui_shift>);
    return "plui.<rvp_width>\t%0,%2";
  }
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])

;; Scalar constant patterns - handled by riscv_output_move
(define_insn "*riscv_pli_const"
  [(set (match_operand:GPR 0 "register_operand" "=r")
	(match_operand:GPR 1 "pli_const_operand" "i"))]
  "TARGET_RVP"
  { return riscv_output_move (operands[0], operands[1]); }
  [(set_attr "type" "arith")
   (set_attr "mode" "<MODE>")])
