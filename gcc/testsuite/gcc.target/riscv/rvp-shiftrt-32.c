/* { dg-do compile } */
/* { dg-options "-march=rv32gcp0p19 -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed short pv2hi __attribute__((vector_size (4)));
typedef signed char pv4qi __attribute__((vector_size (4)));

typedef unsigned short pvu2hi __attribute__((vector_size (4)));
typedef unsigned char pvu4qi __attribute__((vector_size (4)));

pv2hi
test_srai_hi (pv2hi a)
{
  return a >> 1;
}

pv2hi
test_sra_hi (pv2hi a, int b)
{
  return a >> b;
}

pv4qi
test_srai_bi (pv4qi a)
{
  return a >> 1;
}

pv4qi
test_sra_bi (pv4qi a, int b)
{
  return a >> b;
}

pvu2hi
test_srli_hi (pvu2hi a)
{
  return a >> 1;
}

pvu2hi
test_srl_hi (pvu2hi a, int b)
{
  return a >> b;
}

pvu4qi
test_srli_bi (pvu4qi a)
{
  return a >> 1;
}

pvu4qi
test_srl_bi (pvu4qi a, int b)
{
  return a >> b;
}

/* { dg-final { scan-assembler-times "psrai\.h" 1 } } */
/* { dg-final { scan-assembler-times "psra\.hs" 1 } } */
/* { dg-final { scan-assembler-times "psrai\.b" 1 } } */
/* { dg-final { scan-assembler-times "psra\.bs" 1 } } */
/* { dg-final { scan-assembler-times "psrli\.h" 1 } } */
/* { dg-final { scan-assembler-times "psrl\.hs" 1 } } */
/* { dg-final { scan-assembler-times "psrli\.b" 1 } } */
/* { dg-final { scan-assembler-times "psrl\.bs" 1 } } */
