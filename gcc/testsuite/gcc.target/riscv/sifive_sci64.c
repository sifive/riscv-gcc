/* { dg-do compile } */
/* { dg-skip-if "" { *-*-* } { "-flto" } { "" } } */
/* { dg-options "-march=rv64i_xsfsci -O2 -mabi=lp64" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include <sifive_sci.h>
#include <stdint-gcc.h>
int foo_0_r(int a, int b)
{
/*
** foo_0_r:
**   ...
**   sf.sci.0.r\s*7, 0, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_0_r_x_xx_64(7, 0, a, b);
}

int bar_0_r(int a, int b)
{
/*
** bar_0_r:
**   ...
**   sf.sci.0.r\s*6, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_0_r_x_xx_se_64(6, 127, a, b);
}

void zoo_0_r(int a, int b)
{
/*
** zoo_0_r:
**   ...
**   sf.sci.0.r\s*5, 127, zero, a0, a1
**   ...
*/
  __riscv_sf_sci_0_r_xx_se_64(5, 127, a, b);
}

int foo_1_r(int a, int b)
{
/*
** foo_1_r:
**   ...
**   sf.sci.1.r\s*4, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_1_r_x_xx_64(4, 127, a, b);
}

int bar_1_r(int a, int b)
{
/*
** bar_1_r:
**   ...
**   sf.sci.1.r\s*3, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_1_r_x_xx_se_64(3, 127, a, b);
}

void zoo_1_r(int a, int b)
{
/*
** zoo_1_r:
**   ...
**   sf.sci.1.r\s*1, 127, zero, a0, a1
**   ...
*/
  __riscv_sf_sci_1_r_xx_se_64(1, 127, a, b);
}

int foo_2_r(int a, int b)
{
/*
** foo_2_r:
**   ...
**   sf.sci.2.r\s*0, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_2_r_x_xx_64(0, 127, a, b);
}

int bar_2_r(int a, int b)
{
/*
** bar_2_r:
**   ...
**   sf.sci.2.r\s*0, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_2_r_x_xx_se_64(0, 127, a, b);
}

void zoo_2_r(int a, int b)
{
/*
** zoo_2_r:
**   ...
**   sf.sci.2.r\s*0, 127, zero, a0, a1
**   ...
*/
  __riscv_sf_sci_2_r_xx_se_64(0, 127, a, b);
}

int foo_3_r(int a, int b)
{
/*
** foo_3_r:
**   ...
**   sf.sci.3.r\s*0, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_3_r_x_xx_64(0, 127, a, b);
}

int bar_3_r(int a, int b)
{
/*
** bar_3_r:
**   ...
**   sf.sci.3.r\s*0, 127, a0, a0, a1
**   ...
*/
  return __riscv_sf_sci_3_r_x_xx_se_64(0, 127, a, b);
}

void zoo_3_r(int a, int b)
{
/*
** zoo_3_r:
**   ...
**   sf.sci.3.r\s*0, 127, zero, a0, a1
**   ...
*/
  __riscv_sf_sci_3_r_xx_se_64(0, 127, a, b);
}

int foo_0_i(uint32_t x)
{
/*
** foo_0_i:
**   ...
**   sf.sci.0.i\s*7, a0, a0, 0
**   ...
*/
  return __riscv_sf_sci_0_i_x_xi_64(7, x, 0);
}

int bar_0_i(uint32_t x)
{
/*
** bar_0_i:
**   ...
**   sf.sci.0.i\s*6, a0, a0, 4095
**   ...
*/
  return __riscv_sf_sci_0_i_x_xi_se_64(6, x, 4095);
}

void zoo_0_i(uint32_t x)
{
/*
** zoo_0_i:
**   ...
**   sf.sci.0.i\s*5, zero, a0, 2048
**   ...
*/
  __riscv_sf_sci_0_i_xi_se_64(5, x, 2048);
}

int foo_1_i(uint32_t x)
{
/*
** foo_1_i:
**   ...
**   sf.sci.1.i\s*7, a0, a0, 0
**   ...
*/
  return __riscv_sf_sci_1_i_x_xi_64(7, x, 0);
}

int bar_1_i(uint32_t x)
{
/*
** bar_1_i:
**   ...
**   sf.sci.1.i\s*6, a0, a0, 4095
**   ...
*/
  return __riscv_sf_sci_1_i_x_xi_se_64(6, x, 4095);
}

void zoo_1_i(uint32_t x)
{
/*
** zoo_1_i:
**   ...
**   sf.sci.1.i\s*5, zero, a0, 2048
**   ...
*/
  __riscv_sf_sci_1_i_xi_se_64(5, x, 2048);
}

int foo_2_i(uint32_t x)
{
/*
** foo_2_i:
**   ...
**   sf.sci.2.i\s*7, a0, a0, 0
**   ...
*/
  return __riscv_sf_sci_2_i_x_xi_64(7, x, 0);
}

int bar_2_i(uint32_t x)
{
/*
** bar_2_i:
**   ...
**   sf.sci.2.i\s*6, a0, a0, 4095
**   ...
*/
  return __riscv_sf_sci_2_i_x_xi_se_64(6, x, 4095);
}

void zoo_2_i(uint32_t x)
{
/*
** zoo_2_i:
**   ...
**   sf.sci.2.i\s*5, zero, a0, 2048
**   ...
*/
  __riscv_sf_sci_2_i_xi_se_64(5, x, 2048);
}

int foo_3_i(uint32_t x)
{
/*
** foo_3_i:
**   ...
**   sf.sci.3.i\s*7, a0, a0, 0
**   ...
*/
  return __riscv_sf_sci_3_i_x_xi_64(7, x, 0);
}

int bar_3_i(uint32_t x)
{
/*
** bar_3_i:
**   ...
**   sf.sci.3.i\s*6, a0, a0, 4095
**   ...
*/
  return __riscv_sf_sci_3_i_x_xi_se_64(6, x, 4095);
}

void zoo_3_i(uint32_t x)
{
/*
** zoo_3_i:
**   ...
**   sf.sci.3.i\s*5, zero, a0, 2048
**   ...
*/
  __riscv_sf_sci_3_i_xi_se_64(5, x, 2048);
}

int foo_0_u()
{
/*
** foo_0_u:
**   ...
**   sf.sci.0.u\s*a0, 0
**   ...
*/
  return __riscv_sf_sci_0_u_x_i_64(0);
}

int bar_0_u()
{
/*
** bar_0_u:
**   ...
**   sf.sci.0.u\s*a0, 4095
**   ...
*/
  return __riscv_sf_sci_0_u_x_i_se_64(4095);
}

void zoo_0_u()
{
/*
** zoo_0_u:
**   ...
**   sf.sci.0.u\s*zero, 2048
**   ...
*/
  __riscv_sf_sci_0_u_i_se_64(2048);
}

int foo_1_u()
{
/*
** foo_1_u:
**   ...
**   sf.sci.1.u\s*a0, 0
**   ...
*/
  return __riscv_sf_sci_1_u_x_i_64(0);
}

int bar_1_u()
{
/*
** bar_1_u:
**   ...
**   sf.sci.1.u\s*a0, 4095
**   ...
*/
  return __riscv_sf_sci_1_u_x_i_se_64(4095);
}

void zoo_1_u()
{
/*
** zoo_1_u:
**   ...
**   sf.sci.1.u\s*zero, 2048
**   ...
*/
  __riscv_sf_sci_1_u_i_se_64(2048);
}

int foo_2_u()
{
/*
** foo_2_u:
**   ...
**   sf.sci.2.u\s*a0, 0
**   ...
*/
  return __riscv_sf_sci_2_u_x_i_64(0);
}

int bar_2_u()
{
/*
** bar_2_u:
**   ...
**   sf.sci.2.u\s*a0, 4095
**   ...
*/
  return __riscv_sf_sci_2_u_x_i_se_64(4095);
}

void zoo_2_u()
{
/*
** zoo_2_u:
**   ...
**   sf.sci.2.u\s*zero, 2048
**   ...
*/
  __riscv_sf_sci_2_u_i_se_64(2048);
}

int foo_3_u()
{
/*
** foo_3_u:
**   ...
**   sf.sci.3.u\s*a0, 0
**   ...
*/
  return __riscv_sf_sci_3_u_x_i_64(0);
}

int bar_3_u()
{
/*
** bar_3_u:
**   ...
**   sf.sci.3.u\s*a0, 4095
**   ...
*/
  return __riscv_sf_sci_3_u_x_i_se_64(4095);
}

void zoo_3_u()
{
/*
** zoo_3_u:
**   ...
**   sf.sci.3.u\s*zero, 2048
**   ...
*/
  __riscv_sf_sci_3_u_i_se_64(2048);
}

void foo_0_x()
{
/*
** foo_0_x:
**   ...
**   sf.sci.0.x\s*0
**   ...
*/
  __riscv_sf_sci_0_x_i_se_64(0);
}

void foo_1_x()
{
/*
** foo_1_x:
**   ...
**   sf.sci.1.x\s*12345678
**   ...
*/
  __riscv_sf_sci_1_x_i_se_64(12345678);
}

void foo_2_x()
{
/*
** foo_2_x:
**   ...
**   sf.sci.2.x\s*9101112
**   ...
*/
  __riscv_sf_sci_2_x_i_se_64(9101112);
}

void foo_3_x()
{
/*
** foo_3_x:
**   ...
**   sf.sci.3.x\s*33554431
**   ...
*/
  __riscv_sf_sci_3_x_i_se_64(33554431);
}
