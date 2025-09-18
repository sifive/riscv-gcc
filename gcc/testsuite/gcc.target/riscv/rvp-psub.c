/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* Test basic packed sub operations */

pv8qi
psub_b (pv8qi a, pv8qi b)
{
  return a - b;
}

pv4hi
psub_h (pv4hi a, pv4hi b)
{
  return a - b;
}

pv2si
psub_w (pv2si a, pv2si b)
{
  return a - b;
}

/* { dg-final { scan-assembler-times {\mpsub\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpsub\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpsub\.w\M} 1 } } */

