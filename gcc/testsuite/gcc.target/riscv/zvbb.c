/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvbb -mabi=lp64d" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvbb -mabi=ilp32d" { target { rv32 } } } */

#ifndef __riscv_zvbb
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}
