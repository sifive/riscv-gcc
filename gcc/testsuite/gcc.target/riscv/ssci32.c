/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-flto" } { "" } } */
/* { dg-options "-march=rv32i_xsfsci -O2 -mabi=ilp32" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include <sifive_sci.h>

int foo(int a, int b)
{
/*
** foo:
**   ...
**   sf.sci\s*2, 6, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_x_xx_32(2, 6, a, b);
}

int bar(int a, int b)
{
/*
** bar:
**   ...
**   sf.sci\s*2, 4, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_x_xx_se_32(2, 4, a, b);
}

void zoo(int a, int b)
{
/*
** zoo:
**   ...
**   sf.sci\s*2, 3, zero, a0, a1
**   ...
*/
  __riscv_sf_sci_xx_se_32(2, 3, a, b);
}
