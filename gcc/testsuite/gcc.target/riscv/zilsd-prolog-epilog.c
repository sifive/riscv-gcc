/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that Zilsd is used in function prolog/epilog to save/restore
   callee-saved register pairs.

   Zilsd requires:
   - Even-odd register pairs (e.g., s0-s1, s2-s3, s4-s5)
   - 8-byte aligned offsets to avoid misaligned exceptions

   The expected layout (with padding for 8-byte alignment):
   - ra at offset 64 (single sw)
   - s0-s1 pair at offset 56 (sd s0,56(sp))
   - s2-s3 pair at offset 48 (sd s2,48(sp))
   - s4-s5 pair at offset 40 (sd s4,40(sp))
   - s6 at offset 36 (single sw)  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-68
**   sw\tra,64\(sp\)
**   sd\ts0,56\(sp\)
**   sd\ts2,48\(sp\)
**   sd\ts4,40\(sp\)
**   ...
**   sw\ts6,36\(sp\)
**   ...
**   lw\tra,64\(sp\)
**   ld\ts0,56\(sp\)
**   ...
**   ld\ts2,48\(sp\)
**   ld\ts4,40\(sp\)
**   lw\ts6,36\(sp\)
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
