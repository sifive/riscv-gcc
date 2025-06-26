/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

class Base {
public:
  virtual Base *memfunc3(int) { return reinterpret_cast<Base *>(1); }
};

class Derived : public Base {
public:
  Derived *memfunc3(int) override { return reinterpret_cast<Derived *>(2); }
};

class DerivedDerived : public Derived {
public:
  DerivedDerived *memfunc3(int) override { return reinterpret_cast<DerivedDerived *>(3); }
};

int main() {
  Base *b = new DerivedDerived();
  void *v1 = b->memfunc3(10);
  if (v1 != reinterpret_cast<void *>(3))
    __builtin_abort();

  Derived *d = new DerivedDerived();
  void *v2 = d->memfunc3(1);
  if (v2 != reinterpret_cast<void *>(3))
    __builtin_abort();

  delete b;
  delete d;
  return 0;
}

/* { dg-final { scan-assembler-times "M1vFPviE" 5 } } */
