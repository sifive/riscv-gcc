/* { dg-do compile } */
/* { dg-skip-if "vectorized on RISC-V with vector extension, preventing split-paths analysis" { riscv_v } } */
/* { dg-skip-if "skip on RISC-V with Zvbb support" { riscv_zvbb_ok } } */
/* { dg-options "-O2 -fsplit-paths -fdump-tree-split-paths-details " } */
/* PR tree-optimization/112402 */
/* This is similar to split-path-2.c but instead of the add
   being inside both sides, we have a constant. */

int
foo(signed char *p, int n)
{
  int s = 0;
  int i;

  for (i = 0; i < n; i++) {
    int t;
    if (p[i] >= 0)
      t = 1;
    else
      t = -1;
    s += t;
  }

  return s;
}

/* { dg-final { scan-tree-dump "appears to be a join point for if-convertable" "split-paths" } } */

