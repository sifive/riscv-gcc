/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLI/PLUI with various operations (RV32).  */

typedef unsigned int uint32_t;

/* Return replicated byte constant.  */
uint32_t ret_pli_b (void) { return 0x41414141U; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,65} } } */

/* Return replicated halfword constant.  */
uint32_t ret_pli_h (void) { return 0x00640064U; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,100} } } */

/* Return PLUI.H constant.  */
uint32_t ret_plui_h (void) { return 0x7FC07FC0U; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

/* Return another replicated byte constant.  */
uint32_t ret_pli_b_85 (void) { return 0x55555555U; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,85} } } */

