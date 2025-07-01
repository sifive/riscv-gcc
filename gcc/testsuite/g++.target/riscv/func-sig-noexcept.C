/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-std=c++11 -O0 -fno-inline -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

struct A {
  int val;
};

int __attribute__((noinline)) foo(A a) noexcept {
  return a.val;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"Fi1AE\"\\)" } } */
