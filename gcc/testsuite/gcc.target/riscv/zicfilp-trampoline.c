/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-require-effective-target trampolines } */
/* { dg-options "-Wpadded -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch" } */
/* The struct internally constructed for the nested function should
   not result in a warning from -Wpadded. */
extern int baz(int (*) (int));
int foo(void)
{
  int k = 3;
  int bar(int x) {
    return x + k;
  }
  return baz(bar);
}
