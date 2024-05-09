/* Verify the -mno-cfi-lp option.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d" } */

__attribute__((landing_pad_value(-1)))
int test1 (void)
{ /* { dg-warning "'landing_pad_value' attribute is out of range" } */
  return 42;
}

__attribute__((landing_pad_value(0x100000)))
int test2 (void)
{ /* { dg-warning "'landing_pad_value' attribute is out of range" } */
  return 42;
}
