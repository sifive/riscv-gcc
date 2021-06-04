;; Scheduling description for Sifive 8.

;; Sifive 8 is a triple-issue, superscalar, out-of-order processor.

;; The Sifive 8 pipeline has 3 major components:
;;  1. The FETCH/DECODE/DISPATCH stages, an in-order front-end,
;;  2. The EXECUTION stage, which is the out-of-order core.
;;  3. The STORE stage, an in-order register storage stage.
;;
;; Since the core executes the instructions out of order, the most important
;; consideration for performance tuning is to make sure that enough decoded
;; instructions are ready for execution in the EXECUTION stage while not
;; stalling the front-end, i.e while not trying to dispatch a decoded
;; instruction to an execution unit whose reservation stations are full.
;; Therefore, we do not model the reservation stations (which is equivalent
;; to pretending that there is only one of them for each execution unit) but
;; only the execution unit, thus preserving some margin in case the unit
;; itself stalls unexpectedly.

;; CPU execution units:
;; ialu            Integer Units: all arithmetic and logic.
;;
;; bru             Branch Resolution Unit: all branches.
;;
;; st              Memory Write Unit: all writes to memory.
;;
;; ld              Memory Read Unit: all reads from memory.
;;
;; imul            Integer Multiply Unit
;;
;; idiv            Integer Divide Unit
;;
;; system          System Unit: all coprocessor accesses.
;;
;; fpu             Floating Point Unit
;;
;; fmul            Floating Point Multiply Unit
;;
;; fdiv            Floating Point Divide Unit

;; Four automata are defined to reduce number of states
;; which a single large automaton will have.
(define_automaton "sifive_8_iex,sifive_8_fex,sifive_8_mem,sifive_8_div")

;; The Sifive 8 has six pipelines:
;; A-pipe       Load, Store
;; B-pipe       ALU, Branch
;; M-pipe       ALU, MUL, DIV and I2F(integer to float instruction)
;; C-pipe       ALU, Conditional move and system for coprocessor accesses
;; F-pipe       FPU, MUL, F2I(float to integer instruction)
;; FM-pipe      FPU, MUL, DIV

(define_cpu_unit "sifive_8_A" "sifive_8_mem")
(define_cpu_unit "sifive_8_B" "sifive_8_iex")
(define_cpu_unit "sifive_8_M" "sifive_8_iex")
(define_cpu_unit "sifive_8_C" "sifive_8_iex")
(define_cpu_unit "sifive_8_F" "sifive_8_fex")
(define_cpu_unit "sifive_8_FM" "sifive_8_fex")

;; Load and store unit.
(define_cpu_unit "sifive_8_ld" "sifive_8_mem")
(define_cpu_unit "sifive_8_st" "sifive_8_mem")

;; Branch unit.
(define_cpu_unit "sifive_8_bru" "sifive_8_iex")

;; Integer and multiply unit.
(define_cpu_unit "sifive_8_ialu" "sifive_8_iex")
(define_cpu_unit "sifive_8_imul" "sifive_8_iex")
(define_cpu_unit "sifive_8_system" "sifive_8_iex")

;; Divide unit.
(define_cpu_unit "sifive_8_idiv" "sifive_8_div")
(define_cpu_unit "sifive_8_fdiv" "sifive_8_div")

;; Float and multiply unit.
(define_cpu_unit "sifive_8_fmul" "sifive_8_fex")
(define_cpu_unit "sifive_8_fpu" "sifive_8_fex")

;; ALU instruction can use pipeline C, B and M.
(define_reservation "int_pipe" "(sifive_8_C|sifive_8_B|sifive_8_M)")
;; FPU instruction can use pipeline F and FM.
(define_reservation "float_pipe" "(sifive_8_F|sifive_8_FM)")

(define_insn_reservation "sifive_8_load" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "load"))
  "sifive_8_A,sifive_8_ld*2")

(define_insn_reservation "sifive_8_fpload" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fpload"))
  "sifive_8_A,sifive_8_ld*3")

(define_insn_reservation "sifive_8_store" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "store"))
  "sifive_8_A+sifive_8_st")

(define_insn_reservation "sifive_8_fpstore" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fpstore"))
  "sifive_8_A+sifive_8_st")

(define_insn_reservation "sifive_8_branch" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "branch,jump,call"))
  "sifive_8_B+sifive_8_bru")

(define_insn_reservation "sifive_8_sfb_alu" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "sfb_alu"))
  "sifive_8_C+sifive_8_bru+sifive_8_ialu")

(define_insn_reservation "sifive_8_atomic" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "atomic"))
  "sifive_8_C,sifive_8_system*2")

(define_insn_reservation "sifive_8_mul" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "imul"))
  "sifive_8_M,sifive_8_imul*2")

(define_insn_reservation "sifive_8_div" 33
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "idiv"))
  "sifive_8_M, sifive_8_idiv*32")

(define_insn_reservation "sifive_8_alu" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "unknown,arith,logical,shift,slt,multi,bitmanip,clz,ctz,rotate,shnadd"))
  "int_pipe+sifive_8_ialu")

(define_insn_reservation "sifive_8_cpop" 3
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "cpop"))
  "int_pipe,sifive_8_ialu*2")

(define_insn_reservation "sifive_8_load_immediate" 1
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "nop,const,auipc,move"))
  "int_pipe")

(define_insn_reservation "sifive_8_fma" 4
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fadd,fmul,fmadd"))
  "float_pipe,sifive_8_fmul*3")

(define_insn_reservation "sifive_8_i2f" 2
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "mtc,fcvt_i2f"))
  "sifive_8_M,sifive_8_ialu")

(define_insn_reservation "sifive_8_f2i" 2
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "mfc,fcmp,fcvt_f2i"))
  "sifive_8_F,sifive_8_fpu")

(define_insn_reservation "sifive_8_fmove" 2
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fmove,fcvt"))
  "float_pipe,sifive_8_fpu")

(define_insn_reservation "sifive_8_fdiv_s" 18
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fdiv,fsqrt")
       (eq_attr "mode" "SF"))
  "sifive_8_FM, sifive_8_fdiv*17")

(define_insn_reservation "sifive_8_fdiv_d" 31
  (and (eq_attr "tune" "sifive_8")
       (eq_attr "type" "fdiv,fsqrt")
       (eq_attr "mode" "DF"))
  "sifive_8_FM, sifive_8_fdiv*30")

(define_bypass 1 "sifive_8_load,sifive_8_alu,sifive_8_mul,sifive_8_sfb_alu"
  "sifive_8_alu,sifive_8_branch")

(define_bypass 1 "sifive_8_load,sifive_8_alu,sifive_8_mul,
                  sifive_8_f2i,sifive_8_fmove,sifive_8_sfb_alu"
  "sifive_8_store" "riscv_store_data_bypass_p")

(define_bypass 1 "sifive_8_i2f"
  "sifive_8_fma,sifive_8_f2i,sifive_8_fmove,sifive_8_fdiv_s,sifive_8_fdiv_d")

(define_bypass 1 "sifive_8_f2i"
  "sifive_8_branch,sifive_8_sfb_alu,sifive_8_mul,
   sifive_8_div,sifive_8_alu,sifive_8_cpop")
