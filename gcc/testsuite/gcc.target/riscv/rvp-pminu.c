/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef unsigned char pv8uqi __attribute__((vector_size (8)));
typedef unsigned short pv4uhi __attribute__((vector_size (8)));
typedef unsigned int pv2usi __attribute__((vector_size (8)));

/* Test packed minimum operations (unsigned)
   GCC vector extensions support comparison and selection */

pv8uqi
pminu_b (pv8uqi a, pv8uqi b)
{
  return (a < b) & a | ~(a < b) & b;
}

pv4uhi
pminu_h (pv4uhi a, pv4uhi b)
{
  return (a < b) & a | ~(a < b) & b;
}

pv2usi
pminu_w (pv2usi a, pv2usi b)
{
  return (a < b) & a | ~(a < b) & b;
}

/* { dg-final { scan-assembler-times {\mpminu\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpminu\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpminu\.w\M} 1 } } */

