/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer -mno-zilsd-prolog-epilog" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Oz" "-Og" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

/* Test that -mno-zilsd-prolog-epilog disables Zilsd optimization
   in function prolog/epilog.  */

extern int bar (int);

/*
** foo:
**   addi\tsp,sp,-32
**   sw\tra,28\(sp\)
**   sw\ts0,24\(sp\)
**   sw\ts1,20\(sp\)
**   ...
**   lw\tra,28\(sp\)
**   lw\ts0,24\(sp\)
**   lw\ts1,20\(sp\)
**   ...
**   addi\tsp,sp,32
**   jr\tra
*/
int foo (int a, int b, int c)
{
  int x1 = bar (a);
  int x2 = bar (b);
  int x3 = bar (c);
  return x1 + x2 + x3;
}

