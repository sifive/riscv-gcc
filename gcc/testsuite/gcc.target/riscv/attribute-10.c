/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32i -march=rv32im_sx_unexpectedstring -mabi=ilp32 -mcmodel=medlow" } */
int foo()
{
}
/* { dg-error "unexpected ISA string at end:" "" { target { "riscv*-*-*" } } 0 } */
