/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test .lpad_info directive format according to riscv-asm-manual PR #113.
   Format: .lpad_info <symbol_name>, "$x<function-sig>", %lpad_hash("<signature>") */

int add(int a, int b)
{
  return a + b;
}

void call_add_indirectly(void)
{
  int (*fp)(int, int) = add;
  volatile int result = fp(10, 20);
  (void)result;
}

int main(void)
{
  call_add_indirectly();
  return 0;
}

/* Verify .lpad_info directive format:
   - First parameter: function name (symbol)
   - Second parameter: "$x" prefix followed by signature in quotes
   - Third parameter: %lpad_hash() with signature */

/* Check function entry .lpad_info format */
/* { dg-final { scan-assembler "\\.lpad_info\\s+add,\\s+\"\\\$x\[FE\]\[^\"]*\",\\s+%lpad_hash\\(\"\[FE\]\[^)]*\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+call_add_indirectly,\\s+\"\\\$x\[FE\]\[^\"]*\",\\s+%lpad_hash\\(\"\[FE\]\[^)]*\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main,\\s+\"\\\$x\[FE\]\[^\"]*\",\\s+%lpad_hash\\(\"\[FE\]\[^)]*\"\\)" } } */

/* Check that lpad instruction is generated before .lpad_info at function entry */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\[^)]+\\)\n\\s*\\.lpad_info\\s+add," } } */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\[^)]+\\)\n\\s*\\.lpad_info\\s+call_add_indirectly," } } */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\[^)]+\\)\n\\s*\\.lpad_info\\s+main," } } */

/* Check that .lpad_info for indirect call appears before lui t2 */
/* { dg-final { scan-assembler "\\.lpad_info\\s+add,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(\[^)]+\\)\n\\s*lui\\s+t2" } } */

