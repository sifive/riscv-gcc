/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLI optimization for various constant patterns (RV32).  */

typedef unsigned int uint32_t;

uint32_t pli_b_i32 (void) { return 0x05050505U; }
/* { dg-final { scan-assembler {pli\.b\ta[0-9]+,5} } } */

uint32_t pli_h_i32 (void) { return 0xffc0ffc0U; }
/* { dg-final { scan-assembler {pli\.h\ta[0-9]+,-64} } } */

void pli_b_store_i32 (uint32_t *p) { *p = 0x41414141U; }
/* { dg-final { scan-assembler {pli\.b\ta[0-9]+,65} } } */
