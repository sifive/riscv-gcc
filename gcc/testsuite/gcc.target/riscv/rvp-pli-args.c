/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLI with function arguments and return values (RV32).  */

typedef unsigned int uint32_t;

/* Pass PLI constant as argument.  */
extern void consume (uint32_t);

void pass_pli_b (void) { consume (0x42424242U); }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,66} } } */

void pass_pli_h (void) { consume (0x01000100U); }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,256} } } */

void pass_plui_h (void) { consume (0x7FC07FC0U); }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

/* Return PLI constant.  */
uint32_t ret_pli_b (void) { return 0x55555555U; }
/* { dg-final { scan-assembler {pli\.b\t[a-x0-9]+,85} } } */

uint32_t ret_pli_h (void) { return 0x01FF01FFU; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,511} } } */

uint32_t ret_plui_h (void) { return 0x04000400U; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,16} } } */

/* Conditional return.  */
uint32_t cond_ret_pli (int c) {
    return c ? 0x42424242U : 0x55555555U;
}

