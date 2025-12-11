/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Test that member functions with reference return types get proper signatures.
   According to RISC-V psABI, class references in return types should be
   simplified to 'Rv' (lvalue reference) or 'Ov' (rvalue reference).  */

class Base {
public:
  int value;

  Base() : value(0) {}

  /* Lvalue reference return - should be M1vFRvvE */
  virtual Base& getRef() { return *this; }

  /* Const lvalue reference return - should be M1vFRvvE (ignore const) */
  virtual const Base& getConstRef() const { return *this; }

  /* Rvalue reference return - should be M1vFOvvE */
  virtual Base&& getRvalueRef() { return static_cast<Base&&>(*this); }
};

class Derived : public Base {
public:
  /* Covariant lvalue reference return - should be M1vFRvvE (same as Base) */
  Derived& getRef() override { return *this; }

  /* Covariant const lvalue reference return - should be M1vFRvvE (same as Base) */
  const Derived& getConstRef() const override { return *this; }

  /* Covariant rvalue reference return - should be M1vFOvvE (same as Base) */
  Derived&& getRvalueRef() override { return static_cast<Derived&&>(*this); }
};

class OtherClass {
public:
  int data;
};

class Complex : public Base {
public:
  /* Non-covariant reference return - should be M1vFRvvE */
  virtual OtherClass& getOther() {
    static OtherClass obj;
    return obj;
  }

  /* Pointer return (for comparison) - should be M1vFPvvE */
  virtual Base* getPtr() { return this; }

  /* Non-reference return (for comparison) - should be M1vF4BasevE */
  virtual Base getValue() { return *this; }

  /* Primitive reference return (for comparison) - should be M1vFRivE */
  virtual int& getInt() { return value; }
};

int main() {
  Base b;
  Derived d;
  Complex c;

  /* Test lvalue reference */
  Base& ref1 = b.getRef();
  ref1.value = 1;

  /* Test const lvalue reference */
  const Base& ref2 = b.getConstRef();

  /* Test covariant lvalue reference */
  Derived& ref3 = d.getRef();
  ref3.value = 2;

  /* Test covariant const lvalue reference */
  const Derived& ref4 = d.getConstRef();

  /* Test non-covariant reference */
  OtherClass& ref5 = c.getOther();
  ref5.data = 3;

  /* Test pointer return */
  Base* ptr = c.getPtr();
  ptr->value = 4;

  /* Test value return */
  Base val = c.getValue();

  /* Test primitive reference */
  int& iref = c.getInt();
  iref = 5;

  return 0;
}

/* Test lvalue reference return: Base& getRef() -> M1vFRvvE
   Both Base::getRef() and Derived::getRef() should have the same signature.  */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFRvvE\"\\)" 3 } } */

/* Test const lvalue reference return: const Base& getConstRef() -> M1vKFRvvE
   Note: const qualifier is preserved in the signature (K prefix).
   Both Base::getConstRef() and Derived::getConstRef() should have the same signature.  */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vKFRvvE\"\\)" 2 } } */

/* Test rvalue reference return: Base&& getRvalueRef() -> M1vFOvvE
   Both Base::getRvalueRef() and Derived::getRvalueRef() should have the same signature.  */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFOvvE\"\\)" 2 } } */

/* Test non-covariant reference: OtherClass& getOther() -> M1vFRvvE
   Note: OtherClass is also simplified to 'v' */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFRvvE\"\\)" 3 } } */

/* Test pointer return: Base* getPtr() -> M1vFPvvE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFPvvE\"\\)" 1 } } */

/* Test value return: Base getValue() -> M1vF4BasevE
   Note: non-reference class return is not simplified */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vF4BasevE\"\\)" 1 } } */

/* Test primitive reference: int& getInt() -> M1vFRivE
   Note: primitive types are not simplified */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFRivE\"\\)" 1 } } */

