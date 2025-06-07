/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-std=c++11 -O1 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Verify that LPAD signature is correctly generated for virtual member function calls
   via method pointers (i.e. static_cast + pointer-to-member-function). */

struct Base {
    virtual int f() = 0;
};

struct Derived : public Base {
    virtual int f() final override {
        return 42;
    }
};

extern Base* b;

int main() {
    return (static_cast<Derived*>(b)->*(&Derived::f))();
}

/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FizE\"\\)" } } */
