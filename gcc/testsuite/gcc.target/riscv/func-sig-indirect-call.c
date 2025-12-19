/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test function signature generation for indirect calls */

typedef int (*func_ptr)(int, int);

int add(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int call_function(func_ptr f, int x, int y)
{
  return f(x, y);
}

int test_indirect_call(void)
{
  func_ptr fp = add;
  return call_function(fp, 10, 5);
}

/* Verify function signatures:
   add: int(int, int) -> FiiiE
   subtract: int(int, int) -> FiiiE
   call_function: int(func_ptr, int, int) -> FiPFiiiEiiE
   test_indirect_call: int(void) -> FivE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FiPFiiiEiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FivE\"\\)" } } */

