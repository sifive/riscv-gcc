/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-std=c++11 -O0 -fno-inline -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Test that exception specifications are removed from function signatures.
   According to RISC-V CFI requirements, exception specs should not affect
   the function signature used for control flow integrity checks. */

struct A {
  int val;
};

/* Function with noexcept - should have signature Fi1AE (without Do) */
int __attribute__((noinline)) foo(A a) noexcept {
  return a.val;
}

/* Verify that the signature does not include the exception spec (Do).
   The signature should be Fi1AE, not FDoi1AE. */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"Fi1AE\"\\)" } } */

