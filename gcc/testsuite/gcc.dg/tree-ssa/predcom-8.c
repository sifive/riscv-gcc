/* { dg-do compile } */
/* { dg-skip-if "skip if RISC-V vector extension is enabled" { riscv_v } } */
/* { dg-skip-if "skip on RISC-V with Zvbb support" { riscv_zvbb_ok } } */
/* { dg-options "-O3 -fdump-tree-pcom-details-blocks" } */

int is_sorted(int *a, int n)
{
  for (int i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
      return 0;
  return 1;
}

/* { dg-final { scan-tree-dump "Executing predictive commoning without unrolling" "pcom" } } */
/* { dg-final { scan-tree-dump-not "Invalid sum" "pcom" { xfail aarch64*-*-* } } } */
