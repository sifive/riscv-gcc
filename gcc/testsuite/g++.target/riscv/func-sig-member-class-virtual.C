/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-std=c++11 -O0 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

class V {
public:
  virtual void vcall() {}
};

int main() {
  V v;
  void (V::*ptr)() = &V::vcall;
  (v.*ptr)();
  return 0;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"M1vFvvE\"\\)" } } */
/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"M1vFvvE\"\\)" } } */
