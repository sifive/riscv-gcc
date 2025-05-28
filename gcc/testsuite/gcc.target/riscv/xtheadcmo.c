/* { dg-do compile } */
/* { dg-options "-march=rv32gc_xtheadcmo -mabi=ilp32d" { target { rv32 } } } */
/* { dg-options "-march=rv64gc_xtheadcmo -mabi=lp64d" { target { rv64 } } } */

#ifndef __riscv_xtheadcmo
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}

