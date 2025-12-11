/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

class Base {
public:
  virtual void memfunc1() { result = 1; }
  static int result;
};

class Derived : public Base {
public:
  void memfunc1() override { result = 42; }
};

int Base::result = 0;

int main() {
  Base *b = new Derived();
  b->memfunc1();
  if (Base::result != 42)
    __builtin_abort();
  return 0;
}

/* { dg-final { scan-assembler-times "M1vFvvE" 5 } } */
