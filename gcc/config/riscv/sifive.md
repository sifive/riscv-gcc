(define_c_enum "unspecv" [
    UNSPECV_SSCI_0
    UNSPECV_SSCI_1
    UNSPECV_SSCI_2
    UNSPECV_SSCI_3
    UNSPECV_SSCI_0_X
    UNSPECV_SSCI_1_X
    UNSPECV_SSCI_2_X
    UNSPECV_SSCI_3_X
])

;; Default scheduling for SSCI instructions
(define_insn_reservation "generic_sifive_ssci" 1
  (eq_attr "type" "ssci")
  "alu")

;; SiFive Scalar Coprocessor Interface.
;; R-Type
(define_insn "riscv_sifive_sci_0_r_x_xx_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:QI 2 "immediate_operand" "I")
			    (match_operand:X  3 "register_operand" "r")
			    (match_operand:X  4 "register_operand" "r")]
			   UNSPECV_SSCI_0))]
  "TARGET_XSFSCI"
  "sf.sci.0.r %1, %2, %0, %3, %4"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_0_r_xx_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:QI 1 "immediate_operand" "I")
		       (match_operand:X  2 "register_operand" "r")
		       (match_operand:X  3 "register_operand" "r")]
		      UNSPECV_SSCI_0)]
  "TARGET_XSFSCI"
  "sf.sci.0.r %0, %1, zero, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_r_x_xx_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:QI 2 "immediate_operand" "I")
			    (match_operand:X  3 "register_operand" "r")
			    (match_operand:X  4 "register_operand" "r")]
			   UNSPECV_SSCI_1))]
  "TARGET_XSFSCI"
  "sf.sci.1.r %1, %2, %0, %3, %4"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_r_xx_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:QI 1 "immediate_operand" "I")
		       (match_operand:X  2 "register_operand" "r")
		       (match_operand:X  3 "register_operand" "r")]
		      UNSPECV_SSCI_1)]
  "TARGET_XSFSCI"
  "sf.sci.1.r %0, %1, zero, %2, %3"
  [(set_attr "type" "ssci")])


(define_insn "riscv_sifive_sci_2_r_x_xx_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:QI 2 "immediate_operand" "I")
			    (match_operand:X  3 "register_operand" "r")
			    (match_operand:X  4 "register_operand" "r")]
			   UNSPECV_SSCI_2))]
  "TARGET_XSFSCI"
  "sf.sci.2.r %1, %2, %0, %3, %4"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_r_xx_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:QI 1 "immediate_operand" "I")
		       (match_operand:X  2 "register_operand" "r")
		       (match_operand:X  3 "register_operand" "r")]
		      UNSPECV_SSCI_2)]
  "TARGET_XSFSCI"
  "sf.sci.2.r %0, %1, zero, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_r_x_xx_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:QI 2 "immediate_operand" "I")
			    (match_operand:X  3 "register_operand" "r")
			    (match_operand:X  4 "register_operand" "r")]
			   UNSPECV_SSCI_3))]
  "TARGET_XSFSCI"
  "sf.sci.3.r %1, %2, %0, %3, %4"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_r_xx_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:QI 1 "immediate_operand" "I")
		       (match_operand:X  2 "register_operand" "r")
		       (match_operand:X  3 "register_operand" "r")]
		      UNSPECV_SSCI_3)]
  "TARGET_XSFSCI"
  "sf.sci.3.r %0, %1, zero, %2, %3"
  [(set_attr "type" "ssci")])

;; I-Type
(define_insn "riscv_sifive_sci_0_i_x_xi_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:X  2 "register_operand" "r")
			    (match_operand:HI 3 "immediate_operand" "Ou12")]
			   UNSPECV_SSCI_0))]
  "TARGET_XSFSCI"
  "sf.sci.0.i %1, %0, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_0_i_xi_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:X  1 "register_operand" "r")
		       (match_operand:HI 2 "immediate_operand" "Ou12")]
		      UNSPECV_SSCI_0)]
  "TARGET_XSFSCI"
  "sf.sci.0.i %0, zero, %1, %2"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_i_x_xi_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:X  2 "register_operand" "r")
			    (match_operand:HI 3 "immediate_operand" "Ou12")]
			   UNSPECV_SSCI_1))]
  "TARGET_XSFSCI"
  "sf.sci.1.i %1, %0, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_i_xi_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:X  1 "register_operand" "r")
		       (match_operand:HI 2 "immediate_operand" "Ou12")]
		      UNSPECV_SSCI_1)]
  "TARGET_XSFSCI"
  "sf.sci.1.i %0, zero, %1, %2"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_i_x_xi_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:X  2 "register_operand" "r")
			    (match_operand:HI 3 "immediate_operand" "Ou12")]
			   UNSPECV_SSCI_2))]
  "TARGET_XSFSCI"
  "sf.sci.2.i %1, %0, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_i_xi_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:X  1 "register_operand" "r")
		       (match_operand:HI 2 "immediate_operand" "Ou12")]
		      UNSPECV_SSCI_2)]
  "TARGET_XSFSCI"
  "sf.sci.2.i %0, zero, %1, %2"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_i_x_xi_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:X  2 "register_operand" "r")
			    (match_operand:HI 3 "immediate_operand" "Ou12")]
			   UNSPECV_SSCI_3))]
  "TARGET_XSFSCI"
  "sf.sci.3.i %1, %0, %2, %3"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_i_xi_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:X  1 "register_operand" "r")
		       (match_operand:HI 2 "immediate_operand" "Ou12")]
		      UNSPECV_SSCI_3)]
  "TARGET_XSFSCI"
  "sf.sci.3.i %0, zero, %1, %2"
  [(set_attr "type" "ssci")])

;; U-Type

(define_insn "riscv_sifive_sci_0_u_x_i_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:SI 1 "immediate_operand" "Ou20")]
			   UNSPECV_SSCI_0))]
  "TARGET_XSFSCI"
  "sf.sci.0.u %0, %1"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_0_u_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou20")]
		      UNSPECV_SSCI_0)]
  "TARGET_XSFSCI"
  "sf.sci.0.u zero, %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_u_x_i_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:SI 1 "immediate_operand" "Ou20")]
			   UNSPECV_SSCI_1))]
  "TARGET_XSFSCI"
  "sf.sci.1.u %0, %1"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_u_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou20")]
		      UNSPECV_SSCI_1)]
  "TARGET_XSFSCI"
  "sf.sci.1.u zero, %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_u_x_i_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:SI 1 "immediate_operand" "Ou20")]
			   UNSPECV_SSCI_2))]
  "TARGET_XSFSCI"
  "sf.sci.2.u %0, %1"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_u_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou20")]
		      UNSPECV_SSCI_2)]
  "TARGET_XSFSCI"
  "sf.sci.2.u zero, %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_u_x_i_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:SI 1 "immediate_operand" "Ou20")]
			   UNSPECV_SSCI_3))]
  "TARGET_XSFSCI"
  "sf.sci.3.u %0, %1"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_u_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou20")]
		      UNSPECV_SSCI_3)]
  "TARGET_XSFSCI"
  "sf.sci.3.u zero, %0"
  [(set_attr "type" "ssci")])

;; X-Type

(define_insn "riscv_sifive_sci_0_x_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou25")]
		      UNSPECV_SSCI_0_X)]
  "TARGET_XSFSCI"
  "sf.sci.0.x %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_1_x_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou25")]
		      UNSPECV_SSCI_1_X)]
  "TARGET_XSFSCI"
  "sf.sci.1.x %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_2_x_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou25")]
		      UNSPECV_SSCI_2_X)]
  "TARGET_XSFSCI"
  "sf.sci.2.x %0"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_3_x_i_<mode>"
  [(unspec_volatile:X [(match_operand:SI 0 "immediate_operand" "Ou25")]
		      UNSPECV_SSCI_3_X)]
  "TARGET_XSFSCI"
  "sf.sci.3.x %0"
  [(set_attr "type" "ssci")])
