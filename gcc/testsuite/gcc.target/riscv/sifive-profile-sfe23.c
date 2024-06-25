/* { dg-do compile } */
/* { dg-options "-mriscv-attribute -march=sfe23 -mabi=ilp32 -mcmodel=medlow" } */
int foo()
{
}
/* { dg-final { scan-assembler ".attribute arch, \"rv32i2p1_m2p0_c2p0_zicbop1p0_zicntr2p0_zicond1p0_zicsr2p0_zifencei2p0_zihintntl1p0_zimop1p0_zaamo1p0_zca1p0_zcb1p0_zcmop1p0_zba1p0_zbb1p0_zbs1p0_zkt1p0\"" } } */
