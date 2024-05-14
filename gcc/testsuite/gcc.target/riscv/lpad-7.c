/* Verify the -mcfi-lp=fixed-one.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -mcfi-lp=fixed-one" } */

int foo (void) { return 42; }

/* { dg-final { scan-assembler-times "lpad\t1" 1 } } */
