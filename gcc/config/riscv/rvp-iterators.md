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
  [plus minus smax umax smin umin eq lt ltu])

;; Operations for averaging instructions
(define_code_iterator avg_op [plus minus])

;; Code Attributes

(define_code_attr rvp_optab
  [(plus "add") (minus "sub")
   (smax "smax") (umax "umax") (smin "smin") (umin "umin")
   (eq "eq") (lt "lt") (ltu "ltu")])

(define_code_attr rvp_insn
  [(plus "padd") (minus "psub")
   (smax "pmax") (umax "pmaxu") (smin "pmin") (umin "pminu")
   (eq "pmseq") (lt "pmslt") (ltu "pmsltu")])
