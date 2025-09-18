/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* Test packed minimum operations (signed)
   GCC vector extensions support comparison and selection */

pv8qi
pmin_b (pv8qi a, pv8qi b)
{
  return (a < b) & a | ~(a < b) & b;
}

pv4hi
pmin_h (pv4hi a, pv4hi b)
{
  return (a < b) & a | ~(a < b) & b;
}

pv2si
pmin_w (pv2si a, pv2si b)
{
  return (a < b) & a | ~(a < b) & b;
}

/* { dg-final { scan-assembler-times {\mpmin\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmin\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmin\.w\M} 1 } } */

