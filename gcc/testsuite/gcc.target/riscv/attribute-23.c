/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=rv64i_zicfilp -mabi=lp64 -mcmodel=medlow" } */
int foo()
{
}
/* { dg-final { scan-assembler ".attribute arch, \"rv64i2p1_zicfilp1p0_zicsr2p0\"" } } */
