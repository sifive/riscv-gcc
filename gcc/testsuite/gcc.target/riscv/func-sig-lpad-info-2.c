/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test .lpad_info directive with different function signatures.
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

/* Check that .lpad_info is generated for all function entries */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_void," } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_int," } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_ptr," } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+func_multi," } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+test_indirect_calls," } } */
/* { dg-final { scan-assembler "\\.lpad_info\\s+main," } } */

/* Check that .lpad_info appears before lui t2 for indirect calls */
/* { dg-final { scan-assembler-times "\\.lpad_info.*\n.*lui\\s+t2" 4 } } */

