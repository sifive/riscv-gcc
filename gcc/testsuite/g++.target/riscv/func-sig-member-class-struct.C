/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

struct SBase {
  virtual SBase *memfunc3(int) {
    return reinterpret_cast<SBase *>(1);
  }
};

struct SDerived : public SBase {
  SDerived *memfunc3(int) override {
    return reinterpret_cast<SDerived *>(2);
  }
};

struct SDerivedDerived : public SDerived {
  SDerivedDerived *memfunc3(int) override {
    return reinterpret_cast<SDerivedDerived *>(3);
  }
};

int main() {
  SBase *sb = new SDerivedDerived();
  void *v1 = sb->memfunc3(10);
  if (v1 != reinterpret_cast<void *>(3))
    __builtin_abort();

  SDerived *sd = new SDerivedDerived();
  void *v2 = sd->memfunc3(1);
  if (v2 != reinterpret_cast<void *>(3))
    __builtin_abort();

  delete sb;
  delete sd;

  return 0;
}

/* { dg-final { scan-assembler-times "M1vFPviE" 5 } } */
