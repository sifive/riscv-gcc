/* { dg-do run { target { riscv32*-*-* } } } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer" } */

/* Execution test to verify Zilsd prolog/epilog generates correct code.
   This test verifies that callee-saved registers are correctly
   saved and restored when using Zilsd's sd/ld instructions.  */

volatile int global = 0;

__attribute__((noinline))
int bar (int x)
{
  global++;
  return x * 2;
}

__attribute__((noinline))
int foo (int a, int b, int c, int d, int e, int f, int g, int h)
{
  /* Force use of many callee-saved registers.  */
  int x1 = bar (a);
  int x2 = bar (b);
  int x3 = bar (c);
  int x4 = bar (d);
  int x5 = bar (e);
  int x6 = bar (f);
  int x7 = bar (g);
  int x8 = bar (h);
  return x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8;
}

int main (void)
{
  int result = foo (1, 2, 3, 4, 5, 6, 7, 8);

  /* Expected: (1+2+3+4+5+6+7+8) * 2 = 36 * 2 = 72 */
  if (result != 72)
    __builtin_abort ();

  if (global != 8)
    __builtin_abort ();

  return 0;
}

