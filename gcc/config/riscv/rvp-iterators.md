;; Packed Iterators for the machine description for RISC-V
;; Copyright (C) 2025 Free Software Foundation, Inc.

;; This file is part of GCC.
;;
;; GCC is free software; you can redistribute it and/or modify it
;; under the terms of the GNU General Public License as published by
;; the Free Software Foundation; either version 3, or (at your option)
;; any later version.
;;
;; GCC is distributed in the hope that it will be useful, but
;; WITHOUT ANY WARRANTY; without even the implied warranty of
;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;; General Public License for more details.
;;
;; You should have received a copy of the GNU General Public License
;; along with GCC; see the file COPYING3.  If not see
;; <http://www.gnu.org/licenses/>.

;; Mode Iterators

;; PVPLUI: Packed vector modes for PLUI instructions (halfword and word)
(define_mode_iterator PVPLUI [
  (PV2HI "!TARGET_64BIT") (PV4HI "TARGET_64BIT")
  (PV2SI "TARGET_64BIT")])

;; Element mode for PLI/PLUI vec_duplicate
(define_mode_attr PVALL_ELT [
  (PV4QI "QI") (PV8QI "QI")
  (PV2HI "HI") (PV4HI "HI")
  (PV2SI "SI")])

;; Constraint for PLI vec_duplicate
(define_mode_attr dpli [
  (PV4QI "Os08") (PV8QI "Os08")
  (PV2HI "Os10") (PV4HI "Os10")
  (PV2SI "Os10")])

;; Constraint for PLUI vec_duplicate
(define_mode_attr dplui [
  (PV2HI "Yph06") (PV4HI "Yph06")
  (PV2SI "Yph22")])

;; Shift amount for PLUI (6 for halfword, 22 for word)
(define_mode_attr plui_shift [
  (PV2HI "6") (PV4HI "6")
  (PV2SI "22")])

;; PVQIHI: Packed vector modes for byte and halfword elements only
(define_mode_iterator PVQIHI [(PV4QI "!TARGET_64BIT") (PV2HI "!TARGET_64BIT")
			      (PV8QI "TARGET_64BIT") (PV4HI "TARGET_64BIT")])

;; PVALL: All packed vector modes for basic arithmetic operations
(define_mode_iterator PVALL [(PV4QI "!TARGET_64BIT") (PV2HI "!TARGET_64BIT")
			     (PV8QI "TARGET_64BIT") (PV4HI "TARGET_64BIT")
			     (PV2SI "TARGET_64BIT")])

;; Mode Attributes

;; PVALL_EXT: Widened result mode for each packed mode
(define_mode_attr PVALL_EXT [(PV4QI "PV4HI") (PV2HI "PV2SI")
			     (PV8QI "PV8HI") (PV4HI "PV4SI")
			     (PV2SI "PV2DI")])

;; Element width suffix for RVP instructions
(define_mode_attr rvp_width [(PV8QI "b") (PV4QI "b") (QI "b") (PV4HI "h") (PV2HI "h")
			     (HI "h") (PV2SI "w")])

;; Code Iterators

(define_code_iterator rvp_binop
  [plus ss_plus us_plus
   minus ss_minus us_minus
   smax umax smin umin eq lt ltu])

;; Operations for averaging instructions
(define_code_iterator avg_op [plus minus])

;; Operations for shift instructions
(define_code_iterator shift_op [ashift lshiftrt ashiftrt])

;; Code Attributes

(define_code_attr rvp_optab
  [(plus "add") (ss_plus "ssadd") (us_plus "usadd")
   (minus "sub") (ss_minus "sssub") (us_minus "ussub")
   (smax "smax") (umax "umax") (smin "smin") (umin "umin")
   (eq "eq") (lt "lt") (ltu "ltu")])

(define_code_attr rvp_insn
  [(plus "padd") (ss_plus "psadd") (us_plus "psaddu")
   (minus "psub") (ss_minus "pssub") (us_minus "pssubu")
   (smax "pmax") (umax "pmaxu") (smin "pmin") (umin "pminu")
   (eq "pmseq") (lt "pmslt") (ltu "pmsltu")])

;; Averaging arithmetic instruction names
(define_code_attr avg_insn
  [(plus "paadd")
   (minus "pasub")])

(define_code_attr rvp_shift_optab
  [(ashift   "ashl")
   (lshiftrt "lshr")
   (ashiftrt "ashr")])

(define_code_attr rvp_shift_insn
  [(ashift   "psll")
   (lshiftrt "psrl")
   (ashiftrt "psra")])
