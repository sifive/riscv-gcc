/* Test RISC-V CFILP setjmp call protection functionality.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O2 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -fno-inline" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-g"} } */

#include <setjmp.h>

/* Global jump buffer for setjmp/longjmp.  */
jmp_buf test_env;

/* Normal function that doesn't need LPAD protection.  */
int __attribute__((noinline)) normal_function(int x)
{
  return x + 5;
}

/* Function that calls setjmp - should get LPAD after the call.  */
int test_setjmp_call(void)
{
  int result = setjmp(test_env);
  return result;
}

/* Function that calls both setjmp and normal functions.  */
int test_mixed_calls(void)
{
  int result = 0;

  /* This should get LPAD after it (setjmp can return indirectly).  */
  result += setjmp(test_env);

  /* This should NOT get LPAD after it (normal function call).  */
  result += normal_function(10);

  return result;
}

/* Function with multiple setjmp calls.  */
int test_multiple_setjmp(void)
{
  jmp_buf local_env1, local_env2;
  int result = 0;

  /* Both of these should get LPAD after them.  */
  result += setjmp(local_env1);
  result += setjmp(local_env2);

  /* This should NOT get LPAD.  */
  result += normal_function(20);

  return result;
}

/* Function that demonstrates setjmp in conditional context.  */
int test_conditional_setjmp(int flag)
{
  if (flag) {
    /* This setjmp call should get LPAD protection.  */
    return setjmp(test_env);
  } else {
    /* This normal call should NOT get LPAD protection.  */
    return normal_function(30);
  }
}

/* Check that setjmp calls have LPAD inserted after them.
   The LPAD instruction should appear immediately after the setjmp call.
   Handle both direct calls and PLT calls.  */
/* { dg-final { scan-assembler "call\t.*setjmp.*\n\tlpad\t0" } } */

/* Verify we have the expected number of LPAD instructions for setjmp calls.
   We expect 5 LPAD instructions after setjmp calls across all test functions.
   This matches both "call setjmp" and "call setjmp@plt" patterns.  */
/* { dg-final { scan-assembler-times "call\t_?setjmp(@plt)?\n\tlpad\t0" 5 } } */

/* Ensure that normal function calls don't accidentally get LPAD protection.  */
/* { dg-final { scan-assembler-not "call\tnormal_function\n\tlpad" } } */
