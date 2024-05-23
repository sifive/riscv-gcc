/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=rv64i_zicfiss -mabi=lp64 -mcmodel=medlow" } */
int foo()
{
}
/* { dg-final { scan-assembler ".attribute arch, \"rv64i2p1_zicfiss1p0_zicsr2p0_zimop1p0\"" } } */
