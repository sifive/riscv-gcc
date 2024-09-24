/* Verify the no_cfi_lp attribute.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch" } */

__attribute__((no_cfi_lp))
int foo (void) { return 42; }

/* { dg-final { scan-assembler-not "lpad\t" } } */
