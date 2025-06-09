/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-require-effective-target pthread } */
/* { dg-options "-O2 -ftree-parallelize-loops=4 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

extern void abort(void);

#define N 32
int x[N][N];

void parloop(void)
{
  int i, j;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x[i][j] = i + j + 3;

  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      if (x[i][j] != i + j + 3)
        abort ();
}

int main(void)
{
  parloop();
  return 0;
}

/* { dg-final { scan-assembler-times "parloop._loopfn.0:" 1 } } */
/* { dg-final { scan-assembler-times "lpad\t0" 1 } } */
