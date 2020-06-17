(define_automaton "sifive_8")

;; Sifive 8 Series Base Core
;; This has six pipelines, A (Address), B (Branch, ALU),
;; M (MUL, DIV, ALU and I2F), C (conditional MOV and system),
;; F (FPU, I2F, MUL), FM (FPU, MUL, DIV).
;; Loads, stores use the A-pipe.
;; Branches use the B-pipe;
;; MUL, DIV and I2F use the M-pipe;
;; Conditional move and system access use the C-pipe.
;; ALU use the B, M and C pipes.
;; Floating MUL/DIV use the F-pipe;
;; Floating MUL and F2I use the FM-pipe;

(define_cpu_unit "sifive_8_A" "sifive_8")
(define_cpu_unit "sifive_8_B" "sifive_8")
(define_cpu_unit "sifive_8_M" "sifive_8")
(define_cpu_unit "sifive_8_C" "sifive_8")
(define_cpu_unit "sifive_8_F" "sifive_8")
(define_cpu_unit "sifive_8_FM" "sifive_8")

(define_insn_reservation "sifive_8_load" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "load"))
  "sifive_8_A")

(define_insn_reservation "sifive_8_fpload" 6
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fpload"))
  "sifive_8_A")

(define_insn_reservation "sifive_8_store" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "store"))
  "sifive_8_A")

(define_insn_reservation "sifive_8_fpstore" 6
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fpstore"))
  "sifive_8_A")

(define_insn_reservation "sifive_8_branch" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "branch"))
  "sifive_8_B")

(define_insn_reservation "sifive_8_sfb_alu" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "sfb_alu"))
  "sifive_8_C")

(define_insn_reservation "sifive_8_jump" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "jump,call"))
  "sifive_8_B")

(define_insn_reservation "sifive_8_mul" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "imul"))
  "sifive_8_M")

(define_insn_reservation "sifive_8_div" 16
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "idiv"))
  "sifive_8_M")

(define_insn_reservation "sifive_8_alu" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "unknown,arith,shift,slt,multi,logical,move"))
  "sifive_8_C|sifive_8_B|sifive_8_M")

(define_insn_reservation "sifive_8_load_immediate" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "nop,const,auipc"))
  "sifive_8_C|sifive_8_B|sifive_8_M")

(define_insn_reservation "sifive_8_sfma" 5
  (and (eq_attr "tune" "sifive_8")
       (and (eq_attr "type" "fadd,fmul,fmadd")
	    (eq_attr "mode" "SF")))
  "sifive_8_F|sifive_8_FM")

(define_insn_reservation "sifive_8_dfma" 7
  (and (eq_attr "tune" "sifive_8")
       (and (eq_attr "type" "fadd,fmul,fmadd")
	    (eq_attr "mode" "DF")))
  "sifive_8_F|sifive_8_FM")

(define_insn_reservation "sifive_8_fp_other" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fcvt,fcmp,fmove"))
  "sifive_8_F|sifive_8_FM")

(define_insn_reservation "sifive_8_fdiv_s" 27
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fdiv,fsqrt")
       (eq_attr "mode" "SF"))
  "sifive_8_FM")

(define_insn_reservation "sifive_8_fdiv_d" 56
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fdiv,fsqrt")
       (eq_attr "mode" "DF"))
  "sifive_8_FM")

(define_insn_reservation "sifive_8_i2f" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "mtc"))
  "sifive_8_M")

(define_insn_reservation "sifive_8_f2i" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "mfc"))
  "sifive_8_FM")

(define_insn_reservation "sifive_8_atomic" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "atomic"))
  "sifive_8_C")

(define_bypass 1 "sifive_8_load,sifive_8_alu,sifive_8_mul,sifive_8_f2i,sifive_8_sfb_alu"
  "sifive_8_alu,sifive_8_branch")

(define_bypass 1 "sifive_8_alu,sifive_8_sfb_alu"
  "sifive_8_sfb_alu")

(define_bypass 1 "sifive_8_load,sifive_8_alu,sifive_8_mul,sifive_8_f2i,sifive_8_sfb_alu"
  "sifive_8_store" "riscv_store_data_bypass_p")

(define_bypass 2 "sifive_8_i2f"
  "sifive_8_sfma,sifive_8_dfma,sifive_8_fp_other,sifive_8_fdiv_s,sifive_8_fdiv_d")

(define_bypass 2 "sifive_8_fp_other"
  "sifive_8_sfma,sifive_8_dfma,sifive_8_fp_other,sifive_8_fdiv_s,sifive_8_fdiv_d")

(define_bypass 2 "sifive_8_fp_other"
  "sifive_8_alu,sifive_8_branch")

(define_bypass 2 "sifive_8_fp_other"
  "sifive_8_store" "riscv_store_data_bypass_p")
