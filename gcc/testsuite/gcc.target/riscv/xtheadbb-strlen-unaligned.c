/* { dg-do compile } */
/* { dg-options "-minline-strlen -march=rv32gc_xtheadbb -mabi=ilp32d" { target { rv32 } } } */
/* { dg-options "-minline-strlen -march=rv64gc_xtheadbb -mabi=lp64d" { target { rv64 } } } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-Os" "-Og" "-Oz" } } */

typedef long unsigned int size_t;

size_t
my_str_len (const char *s)
{
  return __builtin_strlen (s);
}

/* { dg-final { scan-assembler-not "th.tstnbz\t" } } */
