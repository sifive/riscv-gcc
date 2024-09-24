/* Verify the -mno-cfi-ss option.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfiss -mabi=lp64d -mno-cfi-ss -fcf-protection=return" } */

int foo (void) { return 42; }

/* { dg-final { scan-assembler-not "sspush\t" } } */
/* { dg-final { scan-assembler-not "sspopchk\t" } } */
