/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that Zilsd offsets are always 8-byte aligned.
   This is required to avoid misaligned exceptions on some implementations.

   The compiler adds padding to ensure 8-byte alignment when necessary.
   All sd/ld offsets must be divisible by 8: 56, 48, 40 are all % 8 == 0.  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-68
**   sw\tra,64\(sp\)
**   sd\ts0,56\(sp\)
**   sd\ts2,48\(sp\)
**   sd\ts4,40\(sp\)
**   ...
**   ld\ts0,56\(sp\)
**   ...
**   ld\ts2,48\(sp\)
**   ld\ts4,40\(sp\)
**   ...
**   addi\tsp,sp,68
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

