(define_c_enum "unspecv" [
    UNSPECV_SSCI
])

;; Default scheduling for SSCI instructions
(define_insn_reservation "generic_sifive_ssci" 1
  (eq_attr "type" "ssci")
  "alu")

(define_insn "riscv_sifive_sci_x_xx_<mode>"
  [(set (match_operand:X 0 "register_operand" "=r")
        (unspec_volatile:X [(match_operand:QI 1 "immediate_operand" "I")
			    (match_operand:QI 2 "immediate_operand" "I")
			    (match_operand:X  3 "register_operand" "r")
			    (match_operand:X  4 "register_operand" "r")]
			   UNSPECV_SSCI))]
  "TARGET_XSFSCI"
  "sf.sci %1, %2, %0, %3, %4"
  [(set_attr "type" "ssci")])

(define_insn "riscv_sifive_sci_xx_<mode>"
  [(unspec_volatile:X [(match_operand:QI 0 "immediate_operand" "I")
		       (match_operand:QI 1 "immediate_operand" "I")
		       (match_operand:X  2 "register_operand" "r")
		       (match_operand:X  3 "register_operand" "r")]
		      UNSPECV_SSCI)]
  "TARGET_XSFSCI"
  "sf.sci %0, %1, zero, %2, %3"
  [(set_attr "type" "ssci")])
