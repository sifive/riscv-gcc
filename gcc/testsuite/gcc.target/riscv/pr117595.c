/* { dg-do compile } */
/* { dg-skip-if "Current RISC-V GCC does not support RVV in big-endian mode" { riscv_v } } */
/* { dg-skip-if "skip on RISC-V with Zvbb support" { riscv_zvbb_ok } } */
/* { dg-options "-mbig-endian" } */

_Atomic enum { E0 } e;
void foo() { e++; }
