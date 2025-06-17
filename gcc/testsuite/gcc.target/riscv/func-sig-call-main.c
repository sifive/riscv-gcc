/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

int main ();

static void __attribute__((noinline))
call_main_indirectly(void)
{
  int (*fp)(int, char **) = main;
  char *fake_argv[] = { "test", 0 };
  volatile int x = fp(1, fake_argv);
  (void)x;
}

int main ()
{
  call_main_indirectly();
  return 0;
}

/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FiiPPcE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiiPPcE\"\\)" } } */
