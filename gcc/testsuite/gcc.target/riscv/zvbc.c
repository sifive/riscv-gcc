/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvbc -mabi=lp64d" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvbc -mabi=ilp32d" { target { rv32 } } } */

#ifndef __riscv_zvbc
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}
