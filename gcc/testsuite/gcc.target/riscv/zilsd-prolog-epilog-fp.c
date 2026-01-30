/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fno-omit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that Zilsd is NOT used when frame pointer is enabled,
   to avoid issues with unwinders that expect s0 (frame pointer)
   at a specific location.

   When frame pointer is enabled, all callee-saved registers should
   be saved/restored using individual sw/lw instructions, not sd/ld.  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-80
**   sw\tra,76\(sp\)
**   sw\ts0,72\(sp\)
**   sw\ts1,68\(sp\)
**   addi\ts0,sp,80
**   sw\ts2,64\(sp\)
**   sw\ts3,60\(sp\)
**   sw\ts4,56\(sp\)
**   sw\ts5,52\(sp\)
**   sw\ts6,48\(sp\)
**   sw\ts7,44\(sp\)
**   ...
**   lw\tra,76\(sp\)
**   lw\ts0,72\(sp\)
**   lw\ts1,68\(sp\)
**   lw\ts2,64\(sp\)
**   lw\ts3,60\(sp\)
**   lw\ts4,56\(sp\)
**   lw\ts5,52\(sp\)
**   lw\ts6,48\(sp\)
**   lw\ts7,44\(sp\)
**   addi\tsp,sp,80
**   jr\tra
*/
int foo (int a, int b, int c, int d, int e, int f, int g, int h)
{
  int x1 = bar (a);
  int x2 = bar (b);
  int x3 = bar (c);
  int x4 = bar (d);
  int x5 = bar (e);
  int x6 = bar (f);
  int x7 = bar (g);
  int x8 = bar (h);
  return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;
}
