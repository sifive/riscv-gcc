/* { dg-do compile } */
/* { dg-options "-march=rv64i -mabi=lp64 -mcmodel=compact" } */
/* { dg-additional-options "-Wriscv-deprecated" } */

int main() {
  return 0;
}

/* { dg-warning "-mcmodel=compact. is deprecated" "" { target riscv*-*-* } 0 } */
