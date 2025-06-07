/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

struct Base {
  virtual void Foo(int x) {
  }
};

struct Filler {
  virtual void Bar() {
  }
};

struct Derived : Filler, Base {
  void Foo(int x) override {
  }
};

int main() {
  Derived d;
  Base* base_ptr = &d;

  base_ptr->Foo (42);
  return 0;
}

/* { dg-final { scan-assembler-times "_ZThn8_N7Derived3FooEi:" 1 } } */
/* { dg-final { scan-assembler-times "lpad\t0" 1 } } */
