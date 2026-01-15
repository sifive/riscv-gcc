/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLI.B instruction for P-extension (RV32).
   PLI.B broadcasts an 8-bit immediate to all byte positions.  */

typedef unsigned int uint32_t;

/* Replicated byte constants that should use pli.b.  */
uint32_t pli_b_42 (void) { return 0x42424242U; }  /* 66 */
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,66} } } */

uint32_t pli_b_7f (void) { return 0x7F7F7F7FU; }  /* 127 (max signed) */
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,127} } } */

uint32_t pli_b_80 (void) { return 0x80808080U; }  /* -128 (min signed) */
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,-128} } } */

/* These use li (more efficient for 0, -1).  */
uint32_t pli_b_00 (void) { return 0x00000000U; }
uint32_t pli_b_ff (void) { return 0xFFFFFFFFU; }

/* Negative tests: not replicated bytes.  */
uint32_t not_pli_b_1 (void) { return 0x01020304U; }
uint32_t not_pli_b_2 (void) { return 0x42424200U; }

/* { dg-final { scan-assembler-times {pli\.b} 3 } } */
