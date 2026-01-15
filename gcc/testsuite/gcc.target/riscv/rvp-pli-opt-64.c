/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLI optimization for various constant patterns (RV64).  */

typedef unsigned long long uint64_t;

uint64_t pli_b_i64 (void) { return 0x8080808080808080ULL; }
/* { dg-final { scan-assembler {pli\.b\ta[0-9]+,-128} } } */

uint64_t pli_h_i64 (void) { return 0x0123012301230123ULL; }
/* { dg-final { scan-assembler {pli\.h\ta[0-9]+,291} } } */

uint64_t pli_w_i64 (void) { return 0xfffffedcfffffedcULL; }
/* { dg-final { scan-assembler {pli\.w\ta[0-9]+,-292} } } */
