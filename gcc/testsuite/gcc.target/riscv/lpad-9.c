/* Verify the landing_pad_value attribute.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch" } */

__attribute__((zerolabel))
int foo (void) { return 42; }

/* { dg-final { scan-assembler-times "lpad\t0" 1 } } */
