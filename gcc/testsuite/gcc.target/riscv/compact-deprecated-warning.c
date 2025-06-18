/* { dg-do compile } */
/* { dg-options "-march=rv64i -mabi=lp64 -mcmodel=compact -Wdeprecated -Wriscv-deprecated" } */

int main() {
  return 0;
}

/* { dg-warning "-mcode-model=compact. is deprecated" "" { target riscv*-*-* } 0 } */
