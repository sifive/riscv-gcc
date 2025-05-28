/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zvksed -mabi=lp64d" { target { rv64 } } } */
/* { dg-options "-march=rv32gc_zvksed -mabi=ilp32d" { target { rv32 } } } */

#ifndef __riscv_zvksed
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}
