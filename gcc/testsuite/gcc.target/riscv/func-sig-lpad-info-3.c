/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test .lpad_info directive format in .riscv.lpadinfo section according to riscv-asm-manual PR #113.
   Format: .lpad_info <symbol_name>, "$x<function-sig>", %lpad_hash("<signature>")
   Verifies that .lpad_info is ONLY in .riscv.lpadinfo section, NOT in code. */

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

/* Verify .riscv.lpadinfo section exists */
/* { dg-final { scan-assembler "\\.section\\s+\\.riscv\\.lpadinfo,\"a\"" } } */

/* Verify section has proper alignment */
/* { dg-final { scan-assembler "\\.section\\s+\\.riscv\\.lpadinfo\[^\\n\]*\\n\\s*\\.p2align\\s+3" } } */

/* Verify .lpad_info directive format in section:
   - First parameter: function name (symbol)
   - Second parameter: "$x" prefix followed by signature in quotes
   - Third parameter: %lpad_hash() with signature */
/* { dg-final { scan-assembler "\\.lpad_info\\s+add,\\s+\"\\\$xFiiiE\",\\s+%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+call_add_indirectly,\\s+\"\\\$xFvvE\",\\s+%lpad_hash\\(\"FvvE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main,\\s+\"\\\$x\[^\"]+\",\\s+%lpad_hash\\(" } } */

/* Verify code has lpad instructions but NO inline .lpad_info */
/* { dg-final { scan-assembler "add:\\n\[^\\n\]*\\n\\s*\\.cfi_startproc\\n\\s*lpad\\s+%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler-not "lpad\\s+%lpad_hash\[^\\n\]*\\n\\s*\\.lpad_info" } } */

/* Verify the order in code: lpad followed by regular instructions, not .lpad_info */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\[^\\n\]*\\n\\s*(?:addi|sd|mv)" } } */

/* Verify indirect call has lui t2 but NO .lpad_info before it */
/* { dg-final { scan-assembler "lui\\s+t2,\\s+%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler-not "\\.lpad_info\[^\\n\]*\\n\\s*lui\\s+t2" } } */

