/* Verify the -fcf-protection=branch.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=fixed-one" } */

int foo (void) { return 42; }

/* { dg-final { scan-assembler-times "lpad\t1" 1 } } */
