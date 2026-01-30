/* { dg-do compile } */
/* { dg-options "-O2 -march=rv64gc -mabi=lp64 -fomit-frame-pointer" } */

/* Test that Zilsd prolog/epilog optimization is NOT used on RV64.
   Zilsd is RV32-only as it reuses RV64's ld/sd encoding.
   On RV64, the normal ld/sd instructions are used for 64-bit values,
   not for register pairs.  */

extern long bar (long);

long foo (long a, long b, long c, long d)
{
  long x1 = bar (a);
  long x2 = bar (b);
  long x3 = bar (c);
  long x4 = bar (d);
  return x1 + x2 + x3 + x4;
}

/* On RV64, sd/ld are used for single 64-bit registers, not pairs.
   Each sd/ld should save/restore one register.  */
/* { dg-final { scan-assembler "sd\tra," } } */
/* { dg-final { scan-assembler "sd\ts0," } } */
/* { dg-final { scan-assembler "sd\ts1," } } */
/* { dg-final { scan-assembler "ld\tra," } } */
/* { dg-final { scan-assembler "ld\ts0," } } */
/* { dg-final { scan-assembler "ld\ts1," } } */

