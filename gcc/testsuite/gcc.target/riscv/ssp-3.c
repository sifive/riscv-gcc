/* Verify the no_cfi_ss attribute.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfiss -mabi=lp64d -fcf-protection=return" } */

__attribute__((no_cfi_ss))
int foo (void) { return 42; }

/* { dg-final { scan-assembler-not "sspush\t" } } */
/* { dg-final { scan-assembler-not "sspopchk\t" } } */
