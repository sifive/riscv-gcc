/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef unsigned char pv8uqi __attribute__((vector_size (8)));
typedef unsigned short pv4uhi __attribute__((vector_size (8)));
typedef unsigned int pv2usi __attribute__((vector_size (8)));

/* Test packed maximum operations (unsigned)
   GCC vector extensions support comparison and selection */

pv8uqi
pmaxu_b (pv8uqi a, pv8uqi b)
{
  return (a > b) & a | ~(a > b) & b;
}

pv4uhi
pmaxu_h (pv4uhi a, pv4uhi b)
{
  return (a > b) & a | ~(a > b) & b;
}

pv2usi
pmaxu_w (pv2usi a, pv2usi b)
{
  return (a > b) & a | ~(a > b) & b;
}

/* { dg-final { scan-assembler-times {\mpmaxu\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmaxu\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmaxu\.w\M} 1 } } */

