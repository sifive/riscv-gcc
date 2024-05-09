/* Verify the landing_pad_value attribute.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d" } */

__attribute__((landing_pad_value(10)))
int foo (void) { return 42; }

/* { dg-final { scan-assembler-times "lpad\t10" 1 } } */
