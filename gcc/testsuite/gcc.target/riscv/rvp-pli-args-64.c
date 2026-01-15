/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLI with function arguments and return values (RV64).  */

typedef unsigned long long uint64_t;

/* Pass PLI constant as argument.  */
extern void consume (uint64_t);

void pass_pli_b (void) { consume (0x4242424242424242ULL); }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,66} } } */

void pass_pli_h (void) { consume (0x0100010001000100ULL); }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,256} } } */

void pass_pli_w (void) { consume (0x0000010000000100ULL); }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,256} } } */

void pass_plui_h (void) { consume (0x7FC07FC07FC07FC0ULL); }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

void pass_plui_w (void) { consume (0x7FC000007FC00000ULL); }
/* { dg-final { scan-assembler {plui\.w\t[a-x0-9]+,511} } } */

/* Return PLI constant.  */
uint64_t ret_pli_b (void) { return 0x5555555555555555ULL; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,85} } } */

uint64_t ret_pli_h (void) { return 0x01FF01FF01FF01FFULL; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,511} } } */

uint64_t ret_pli_w (void) { return 0x000001FF000001FFULL; }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,511} } } */

uint64_t ret_plui_h (void) { return 0x0400040004000400ULL; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,16} } } */

uint64_t ret_plui_w (void) { return 0x0400000004000000ULL; }
/* { dg-final { scan-assembler {plui\.w\t[a-x0-9]+,16} } } */

