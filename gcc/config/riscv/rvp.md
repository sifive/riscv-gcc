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
