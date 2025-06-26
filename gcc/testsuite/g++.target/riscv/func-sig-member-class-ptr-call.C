/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-std=c++11 -O1 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

class B {
public:
  virtual int bar(int y) { return y + 2; }
};

int call_via_fp(B* b, int (B::*fp)(int)) {
  int (B::*tmp)(int) = fp;
  return (b->*tmp)(5);
}

int main() {
  B b;
  int result = call_via_fp(&b, &B::bar);
  if (result != 7)
    __builtin_abort();

  return 0;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"M1vFiiE\"\\)" } } */
/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"M1vFiiE\"\\)" } } */
