/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test Zilsd with fewer callee-saved registers.
   When only s0-s1 pair is needed, Zilsd should still be used.

   Expected layout:
   - ra at offset 32 (single sw)
   - s0-s1 pair at offset 24 (sd s0,24(sp))  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-36
**   sw\tra,32\(sp\)
**   sd\ts0,24\(sp\)
**   ...
**   lw\tra,32\(sp\)
**   ...
**   ld\ts0,24\(sp\)
**   ...
**   addi\tsp,sp,36
**   jr\tra
*/
int foo (int a, int b, int c)
{
  int x1 = bar (a);
  int x2 = bar (b);
  int x3 = bar (c);
  return x1 + x2 + x3;
}

