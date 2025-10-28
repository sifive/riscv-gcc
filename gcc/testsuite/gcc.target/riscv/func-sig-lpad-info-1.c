/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test that .lpad_info directives are generated in .riscv.lpadinfo section.
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

/* Check that .riscv.lpadinfo section is generated */
/* { dg-final { scan-assembler "\\.section\\s+\\.riscv\\.lpadinfo" } } */

/* Check that .lpad_info directives are in the section */
/* { dg-final { scan-assembler "\\.section\\s+\\.riscv\\.lpadinfo\[^\\n\]*\\n\\s*\\.p2align\\s+3\\n\\s*\\.lpad_info" } } */

/* Check that all functions have .lpad_info entries */
/* { dg-final { scan-assembler "\\.lpad_info\\s+target_func,\\s+\"\\\$xFiiiE\",\\s+%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+indirect_call_test,\\s+\"\\\$xFvvE\",\\s+%lpad_hash\\(\"FvvE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(" } } */

/* Check that code has lpad instructions but NO .lpad_info */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(" } } */
/* { dg-final { scan-assembler-not "\\.text\[^\\n\]*\\n\[^\\n\]*\\.lpad_info" } } */

