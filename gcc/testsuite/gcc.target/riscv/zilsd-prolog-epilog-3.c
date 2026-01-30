/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that Zilsd is NOT used when there's only one callee-saved register
   (no pair available).  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-32
**   sw\tra,28\(sp\)
**   sw\ts0,24\(sp\)
**   ...
**   lw\tra,28\(sp\)
**   ...
**   lw\ts0,24\(sp\)
**   addi\tsp,sp,32
**   jr\tra
*/
int foo (int a, int b)
{
  int x1 = bar (a);
  int x2 = bar (b);
  return x1 + x2;
}

