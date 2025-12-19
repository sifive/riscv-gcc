/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

int foo (int n, char m[1][n])
{
  return 0;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiiPAE\"\\)" } } */
