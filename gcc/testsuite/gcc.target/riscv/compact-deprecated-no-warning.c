/* { dg-do compile } */
/* { dg-options "-march=rv64i -mabi=lp64 -mcmodel=compact -Wdeprecated" } */

int main() {
  return 0;
}

/* { dg-bogus "-mcode-model=compact. is deprecated" "" { target riscv*-*-* } 0 } */
