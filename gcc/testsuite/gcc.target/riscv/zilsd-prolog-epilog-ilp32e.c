/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32e_zilsd -mabi=ilp32e -fomit-frame-pointer" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that Zilsd works correctly with ilp32e ABI which has only
   4-byte stack alignment (instead of 16-byte for ilp32).
   The compiler should still ensure 8-byte alignment for Zilsd pairs.  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-20
**   sw\tra,16\(sp\)
**   sd\ts0,8\(sp\)
**   ...
**   lw\tra,16\(sp\)
**   ld\ts0,8\(sp\)
**   addi\tsp,sp,20
**   jr\tra
*/
int foo (int a, int b, int c)
{
  int x1 = bar (a);
  int x2 = bar (b);
  int x3 = bar (c);
  return x1 + x2 + x3;
}

