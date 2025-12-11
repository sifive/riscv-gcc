/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Test all examples from RISC-V psABI PR #434
   https://github.com/riscv-non-isa/riscv-elf-psabi-doc/pull/434/changes */

/* Non-member function example */
double foo(int a, float *b) {
  return a + *b;
}

/* Class hierarchy for member function examples */
class Base {
public:
  virtual void memfunc1();                    /* M1vFvvE */
  virtual void memfunc2(int);                 /* M1vFviE */
  virtual Base *memfunc3(int);                /* M1vFPviE */
};

class OtherBase {
public:
  virtual void memfunc2(int);                 /* M1vFviE */
};

class Derived : public Base {
public:
  void memfunc1() override;                   /* M1vFvvE */
  void memfunc2(int) override;                /* M1vFviE */
  Derived *memfunc3(int) override;            /* M1vFPviE (covariant) */
  virtual void memfunc4(double);              /* M1vFvdE */
  virtual void memfunc5();                    /* M1vFvvE */
};

class OtherClass {
public:
  int data;
};

class DerivedDerived : public Derived, public OtherBase {
public:
  void memfunc2(int) override;                /* M1vFviE */
  DerivedDerived *memfunc3(int) override;     /* M1vFPviE (covariant) */
  void memfunc4(double) override;             /* M1vFvdE */
  virtual DerivedDerived *memfunc6();         /* M1vFPvvE */
  virtual OtherClass *memfunc7(float);        /* M1vFPvfE */
  virtual OtherClass &memfunc8();             /* M1vFRvvE */
  virtual OtherClass memfunc9(float);         /* M1vF10OtherClassfE */
  virtual int *memfunc10();                   /* M1vFPivE */
};

/* Implementations */
void Base::memfunc1() {}
void Base::memfunc2(int) {}
Base *Base::memfunc3(int) { return this; }

void OtherBase::memfunc2(int) {}

void Derived::memfunc1() {}
void Derived::memfunc2(int) {}
Derived *Derived::memfunc3(int) { return this; }
void Derived::memfunc4(double) {}
void Derived::memfunc5() {}

void DerivedDerived::memfunc2(int) {}
DerivedDerived *DerivedDerived::memfunc3(int) { return this; }
void DerivedDerived::memfunc4(double) {}
DerivedDerived *DerivedDerived::memfunc6() { return this; }
OtherClass *DerivedDerived::memfunc7(float) {
  static OtherClass obj;
  return &obj;
}
OtherClass &DerivedDerived::memfunc8() {
  static OtherClass obj;
  return obj;
}
OtherClass DerivedDerived::memfunc9(float) {
  OtherClass obj;
  return obj;
}
int *DerivedDerived::memfunc10() {
  static int x = 0;
  return &x;
}

int main() {
  /* Test non-member function */
  float f = 1.0f;
  foo(1, &f);

  /* Test member functions */
  Base b;
  b.memfunc1();
  b.memfunc2(1);
  b.memfunc3(1);

  Derived d;
  d.memfunc1();
  d.memfunc2(1);
  d.memfunc3(1);
  d.memfunc4(1.0);
  d.memfunc5();

  DerivedDerived dd;
  dd.memfunc2(1);
  dd.memfunc3(1);
  dd.memfunc4(1.0);
  dd.memfunc6();
  dd.memfunc7(1.0f);
  dd.memfunc8();
  dd.memfunc9(1.0f);
  dd.memfunc10();

  return 0;
}

/* Test non-member function: foo is encoded as FdiPfE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"FdiPfE\"\\)" 1 } } */

/* Test Base::memfunc1 and Derived::memfunc1: both encoded as M1vFvvE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFvvE\"\\)" 3 } } */

/* Test Base::memfunc2, OtherBase::memfunc2, Derived::memfunc2, and DerivedDerived::memfunc2:
   all encoded as M1vFviE
   Note: DerivedDerived also generates a thunk for OtherBase::memfunc2, so total is 5 */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFviE\"\\)" 5 } } */

/* Test Base::memfunc3, Derived::memfunc3, and DerivedDerived::memfunc3:
   all encoded as M1vFPviE (covariant return type) */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFPviE\"\\)" 3 } } */

/* Test Derived::memfunc4 and DerivedDerived::memfunc4: both encoded as M1vFvdE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFvdE\"\\)" 2 } } */

/* Test Derived::memfunc5: encoded as M1vFvvE */
/* Note: This is already counted in the M1vFvvE test above (total 3) */

/* Test DerivedDerived::memfunc6: encoded as M1vFPvvE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFPvvE\"\\)" 1 } } */

/* Test DerivedDerived::memfunc7: encoded as M1vFPvfE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFPvfE\"\\)" 1 } } */

/* Test DerivedDerived::memfunc8: encoded as M1vFRvvE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFRvvE\"\\)" 1 } } */

/* Test DerivedDerived::memfunc9: encoded as M1vF10OtherClassfE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vF10OtherClassfE\"\\)" 1 } } */

/* Test DerivedDerived::memfunc10: encoded as M1vFPivE */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]%lpad_hash\\(\"M1vFPivE\"\\)" 1 } } */

