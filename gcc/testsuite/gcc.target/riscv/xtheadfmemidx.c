/* { dg-do compile } */
/* { dg-options "-march=rv32gc_xtheadfmemidx -mabi=ilp32d" { target { rv32 } } } */
/* { dg-options "-march=rv64gc_xtheadfmemidx -mabi=lp64d" { target { rv64 } } } */

#ifndef __riscv_xtheadfmemidx
#error "Feature macro not defined"
#endif

int
foo (int a)
{
  return a;
}

