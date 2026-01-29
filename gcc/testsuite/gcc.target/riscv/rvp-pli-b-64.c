/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */

/* Test PLI.B instruction for P-extension (RV64).
   PLI.B broadcasts an 8-bit immediate to all byte positions.  */

typedef unsigned long long uint64_t;

/* Replicated byte constants that should use pli.b.  */
uint64_t pli_b_42 (void) { return 0x4242424242424242ULL; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,66} } } */

uint64_t pli_b_7f (void) { return 0x7F7F7F7F7F7F7F7FULL; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,127} } } */

uint64_t pli_b_80 (void) { return 0x8080808080808080ULL; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,-128} } } */

/* These use li (more efficient for 0, -1).  */
uint64_t pli_b_00 (void) { return 0x0000000000000000ULL; }
uint64_t pli_b_ff (void) { return 0xFFFFFFFFFFFFFFFFULL; }

/* Negative tests: not replicated bytes.  */
uint64_t not_pli_b_1 (void) { return 0x0102030405060708ULL; }
uint64_t not_pli_b_2 (void) { return 0x4242424242424200ULL; }

/* { dg-final { scan-assembler-times {pli\.b} 3 } } */
