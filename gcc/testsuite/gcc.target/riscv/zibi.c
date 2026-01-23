/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-flto" } { "" } } */
/* { dg-options "-march=rv64gc_zibi -mabi=lp64 -mtune=rocket" } */
/* { dg-final { check-function-bodies "**" "" } } */

int foo_n1(int a, int b, int c)
{
/*
** foo_n1:
**   ...
**   b(eq|ne)i	[ats][0-9]+,-1,.L[0-9]+
**   ...
*/
    if (a == -1)
      return b - c;
    return c - b;
}

int foo_zero(int a, int b, int c)
{
/*
** foo_zero:
**   ...
**   b(eq|ne)	[ats][0-9]+,zero,.L[0-9]+
**   ...
*/
    if (a == 0)
      return b - c;
    return c - b;
}

int foo_1(int a, int b, int c)
{
/*
** foo_1:
**   ...
**   b(eq|ne)i	[ats][0-9]+,1,.L[0-9]+
**   ...
*/
    if (a == 1)
      return b - c;
    return c - b;
}

int foo_31(int a, int b, int c)
{
/*
** foo_31:
**   ...
**   b(eq|ne)i	[ats][0-9]+,31,.L[0-9]+
**   ...
*/
    if (a == 31)
      return b - c;
    return c - b;
}

int foo_32(int a, int b, int c)
{
/*
** foo_32:
**   ...
**   b(eq|ne)	[ats][0-9]+,[ats][0-9]+,.L[0-9]+
**   ...
*/
    if (a == 32)
      return b - c;
    return c - b;
}

