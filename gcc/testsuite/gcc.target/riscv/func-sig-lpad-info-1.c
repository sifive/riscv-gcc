/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test that .lpad_info directive is generated for function entries and indirect calls.
   This test verifies the implementation of riscv-asm-manual PR #113. */

int target_func(int x, int y)
{
  return x + y;
}

void indirect_call_test(void)
{
  int (*fp)(int, int) = target_func;
  volatile int result = fp(1, 2);
  (void)result;
}

int main(void)
{
  indirect_call_test();
  return 0;
}

/* Check that .lpad_info is generated for function entries */
/* { dg-final { scan-assembler "\\.lpad_info\\s+target_func,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+indirect_call_test,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(" } } */

/* Check that .lpad_info is generated for indirect calls */
/* { dg-final { scan-assembler "\\.lpad_info\\s+target_func,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(\[^)]+\\).*lui\\s+t2" } } */

