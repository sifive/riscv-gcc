/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test .lpad_info directives with different function signatures in .riscv.lpadinfo section.
   This test verifies various function signature encodings. */

/* Function with no parameters */
void func_void(void)
{
}

/* Function with int parameter */
int func_int(int x)
{
  return x * 2;
}

/* Function with pointer parameters */
void func_ptr(int *p, char *s)
{
  *p = 42;
}

/* Function with multiple parameters */
double func_multi(int a, double b, char c)
{
  return (double)a + b + (double)c;
}

/* Test indirect calls with different signatures */
void test_indirect_calls(void)
{
  void (*fp1)(void) = func_void;
  int (*fp2)(int) = func_int;
  void (*fp3)(int*, char*) = func_ptr;
  double (*fp4)(int, double, char) = func_multi;
  
  fp1();
  volatile int x = fp2(10);
  int val = 0;
  fp3(&val, "test");
  volatile double d = fp4(1, 2.0, 'a');
  
  (void)x;
  (void)d;
}

int main(void)
{
  test_indirect_calls();
  return 0;
}

/* Check that .riscv.lpadinfo section exists */
/* { dg-final { scan-assembler "\\.section\\s+\\.riscv\\.lpadinfo" } } */

/* Check that all functions have .lpad_info entries in the section */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_void,\\s+\"\\\$xFvvE\",\\s+%lpad_hash\\(\"FvvE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_int,\\s+\"\\\$xFiiE\",\\s+%lpad_hash\\(\"FiiE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_ptr,\\s+\"\\\$xFvPiPcE\",\\s+%lpad_hash\\(\"FvPiPcE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_multi,\\s+\"\\\$xFdidcE\",\\s+%lpad_hash\\(\"FdidcE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+test_indirect_calls,\\s+\"\\\$xFvvE\",\\s+%lpad_hash\\(\"FvvE\"\\)" } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main," } } */

/* Verify no duplicate entries (deduplication test) */
/* { dg-final { scan-assembler-times "\\.lpad_info\\s+func_void," 1 } } */
/* { dg-final { scan-assembler-times "\\.lpad_info\\s+func_int," 1 } } */

/* Verify code has lpad but NO inline .lpad_info */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(" } } */
/* { dg-final { scan-assembler-not "lpad\\s+%lpad_hash\[^\\n\]*\\n\\s*\\.lpad_info" } } */

