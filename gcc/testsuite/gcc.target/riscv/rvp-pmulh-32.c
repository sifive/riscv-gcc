/* { dg-do compile } */
/* { dg-options "-march=rv32gcp0p19 -mabi=ilp32 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed short pv2hi __attribute__((vector_size(4)));
typedef signed char pv4qi __attribute__((vector_size(4)));
typedef unsigned short pv2hiu __attribute__((vector_size(4)));
typedef unsigned char pv4qiu __attribute__((vector_size(4)));

pv2hi
test_1 (pv2hi a, pv2hi b)
{
  pv2hi result;
  result[0] = ((int)a[0] * (int)b[0]) >> 16;
  result[1] = ((int)a[1] * (int)b[1]) >> 16;
  return result;
}

pv4qi
test_2 (pv4qi a, pv4qi b)
{
  pv4qi result;
  result[0] = ((short)a[0] * (short)b[0]) >> 8;
  result[1] = ((short)a[1] * (short)b[1]) >> 8;
  result[2] = ((short)a[2] * (short)b[2]) >> 8;
  result[3] = ((short)a[3] * (short)b[3]) >> 8;
  return result;
}

pv2hiu
test_3 (pv2hiu a, pv2hiu b)
{
  pv2hiu result;
  result[0] = ((unsigned int)a[0] * (unsigned int)b[0]) >> 16;
  result[1] = ((unsigned int)a[1] * (unsigned int)b[1]) >> 16;
  return result;
}

pv4qiu
test_4 (pv4qiu a, pv4qiu b)
{
  pv4qiu result;
  result[0] = ((unsigned short)a[0] * (unsigned short)b[0]) >> 8;
  result[1] = ((unsigned short)a[1] * (unsigned short)b[1]) >> 8;
  result[2] = ((unsigned short)a[2] * (unsigned short)b[2]) >> 8;
  result[3] = ((unsigned short)a[3] * (unsigned short)b[3]) >> 8;
  return result;

}

/* { dg-final { scan-assembler-times {\mpmulh\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulh\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulhu\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulhu\.b\M} 1 } } */
