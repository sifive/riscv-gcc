/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test basic function signature generation for simple types */

int add(int a, int b)
{
  return a + b;
}

void print_hello(void)
{
}

double multiply(double x, double y)
{
  return x * y;
}

char get_char(void)
{
  return 'A';
}

/* Verify function signatures:
   add: int(int, int) -> FiiiE
   print_hello: void(void) -> FvvE
   multiply: double(double, double) -> FdddE
   get_char: char(void) -> FcvE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FiiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FvvE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FdddE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FcvE\"\\)" } } */

