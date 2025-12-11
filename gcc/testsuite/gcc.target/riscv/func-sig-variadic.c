/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test function signature generation for variadic functions */

#include <stdarg.h>

int sum(int count, ...)
{
  va_list args;
  int total = 0;
  int i;

  va_start(args, count);
  for (i = 0; i < count; i++)
    total += va_arg(args, int);
  va_end(args);

  return total;
}

void print_values(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  va_end(args);
}

int test_variadic(void)
{
  return sum(3, 1, 2, 3);
}

/* Verify function signatures:
   sum: int(int, ...) -> FiizE
   print_values: void(const char*, ...) -> FvPKczE (K=const)
   test_variadic: int(void) -> FivE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FiizE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FvPKczE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FivE\"\\)" } } */

