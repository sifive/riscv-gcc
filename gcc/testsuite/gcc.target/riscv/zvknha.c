/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvknha -mabi=lp64d" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvknha -mabi=ilp32d" { target { rv32 } } } */

#ifndef __riscv_zvknha
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}
