/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLI/PLUI with various operations (RV64).  */

typedef unsigned long long uint64_t;

/* Return replicated byte constant.  */
uint64_t ret_pli_b (void) { return 0x4141414141414141ULL; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,65} } } */

/* Return replicated halfword constant.  */
uint64_t ret_pli_h (void) { return 0x0064006400640064ULL; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,100} } } */

/* Return replicated word constant.  */
uint64_t ret_pli_w (void) { return 0x0000006400000064ULL; }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,100} } } */

/* Return PLUI.H constant.  */
uint64_t ret_plui_h (void) { return 0x7FC07FC07FC07FC0ULL; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

/* Return PLUI.W constant.  */
uint64_t ret_plui_w (void) { return 0x7FC000007FC00000ULL; }
/* { dg-final { scan-assembler {plui\.w\t[a-x0-9]+,511} } } */

