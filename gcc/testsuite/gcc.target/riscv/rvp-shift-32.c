/* { dg-do compile } */
/* { dg-options "-march=rv32gcp -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef short pv2hi __attribute__((vector_size (4)));
typedef char pv4qi __attribute__((vector_size (4)));

/* Test 16-bit shift immediate operand */
pv2hi
test_sll_hi (pv2hi a)
{
  return a << 1;
}

/* Test 16-bit shift register operand */
pv2hi
test_sll_hs (pv2hi a, int b)
{
  return a << b;
}

/* Test 8-bit shift immediate operand */
pv4qi
test_sll_bi (pv4qi a)
{
  return a << 1;
}

/* Test 8-bit shift register operand */
pv4qi
test_sll_bs (pv4qi a, int b)
{
  return a << b;
}

/* { dg-final { scan-assembler-times "pslli\.h" 1 } } */
/* { dg-final { scan-assembler-times "psll\.hs" 1 } } */
/* { dg-final { scan-assembler-times "pslli\.b" 1 } } */
/* { dg-final { scan-assembler-times "psll\.bs" 1 } } */
