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

/* Test that thunk functions get the same signature as the actual function.
   Both the actual function and the thunk should have signature M1vFviE
   (member function, void return, void* this, int parameter).

   With proper member function signature implementation, thunks now share
   the same signature as the actual function, which is more correct from
   a CFI perspective.  */

/* { dg-final { scan-assembler-times "_ZThn8_N7Derived3FooEi:" 1 } } */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFviE\"\\)" 2 } } */
