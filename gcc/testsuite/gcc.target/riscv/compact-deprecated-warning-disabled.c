/* { dg-do compile } */
/* { dg-options "-march=rv64i -mabi=lp64 -mcmodel=compact -Wdeprecated -Wno-riscv-deprecated" } */

int main() {
  return 0;
}

/* { dg-bogus "-mcmodel=compact. is deprecated" "" { target riscv*-*-* } 0 } */
