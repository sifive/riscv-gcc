/* Test RISC-V CFILP indirect_return attribute functionality.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O2 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -fno-inline" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-g" } } */

/* Function marked with indirect_return attribute.  */
int __attribute__((indirect_return, noinline)) indirect_func(int x)
{
  return x * 2 + 1;
}

/* Another function with indirect_return attribute.  */
int __attribute__((indirect_return, noinline)) another_indirect_func(int x)
{
  return x * 3 + 2;
}

/* Normal function without indirect_return attribute.  */
int __attribute__((noinline)) normal_func(int x)
{
  return x + 10;
}

/* Test function that calls the above functions.  */
int test_calls(void)
{
  int result = 0;

  /* These calls should have LPAD inserted after them.  */
  result += indirect_func(5);
  result += another_indirect_func(7);

  /* This call should NOT have LPAD inserted after it.  */
  result += normal_func(3);

  return result;
}

/* Test function with multiple indirect_return calls.  */
int test_multiple_indirect_calls(void)
{
  int a = indirect_func(1);
  int b = another_indirect_func(2);
  int c = normal_func(3);
  int d = indirect_func(4);

  return a + b + c + d;
}

/* Check that calls to indirect_return functions have LPAD after them.
   The LPAD instruction should appear immediately after the call.
   Handle both direct calls and PLT calls.  */
/* { dg-final { scan-assembler "call\t.*indirect_func.*\n\tlpad\t0" } } */
/* { dg-final { scan-assembler "call\t.*another_indirect_func.*\n\tlpad\t0" } } */

/* Verify we have the expected number of LPAD instructions for indirect calls.
   We expect 3 LPAD instructions: 2 in test_calls + 1 in test_multiple_indirect_calls.
   This matches both direct calls and PLT calls.  */
/* { dg-final { scan-assembler-times "call\tindirect_func\n\tlpad\t0" 3 } } */
/* { dg-final { scan-assembler-times "call\tanother_indirect_func\n\tlpad\t0" 2 } } */
