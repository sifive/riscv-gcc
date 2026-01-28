/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* Test packed maximum operations (signed)
   GCC vector extensions support comparison and selection */

pv8qi
pmax_b (pv8qi a, pv8qi b)
{
  return (a > b) & a | ~(a > b) & b;
}

pv4hi
pmax_h (pv4hi a, pv4hi b)
{
  return (a > b) & a | ~(a > b) & b;
}

pv2si
pmax_w (pv2si a, pv2si b)
{
  return (a > b) & a | ~(a > b) & b;
}

/* { dg-final { scan-assembler-times {\mpmax\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmax\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmax\.w\M} 1 } } */

