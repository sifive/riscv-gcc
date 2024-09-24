/* Verify the -mno-cfi-lp option.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -mno-cfi-lp -fcf-protection=branch" } */

int foo (void) { return 42; }

/* { dg-final { scan-assembler-not "lpad\t" } } */
