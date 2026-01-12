/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed int pv2si __attribute__((vector_size(8)));
typedef signed short pv4hi __attribute__((vector_size(8)));
typedef signed char pv8qi __attribute__((vector_size(8)));
typedef unsigned int pv2siu __attribute__((vector_size(8)));
typedef unsigned short pv4hiu __attribute__((vector_size(8)));
typedef unsigned char pv8qiu __attribute__((vector_size(8)));

pv2si
test_1 (pv2si a, pv2si b)
{
  pv2si result;
  result[0] = ((long)a[0] * (long)b[0]) >> 32; 
  result[1] = ((long)a[1] * (long)b[1]) >> 32; 
  return result;
}

pv4hi
test_2 (pv4hi a, pv4hi b)
{
  pv4hi result;
  result[0] = ((int)a[0] * (int)b[0]) >> 16;
  result[1] = ((int)a[1] * (int)b[1]) >> 16;
  result[2] = ((int)a[2] * (int)b[2]) >> 16;
  result[3] = ((int)a[3] * (int)b[3]) >> 16;
  return result;
}

pv8qi
test_3 (pv8qi a, pv8qi b)
{
  pv8qi result;
  result[0] = ((short)a[0] * (short)b[0]) >> 8;
  result[1] = ((short)a[1] * (short)b[1]) >> 8;
  result[2] = ((short)a[2] * (short)b[2]) >> 8;
  result[3] = ((short)a[3] * (short)b[3]) >> 8;
  result[4] = ((short)a[4] * (short)b[4]) >> 8;
  result[5] = ((short)a[5] * (short)b[5]) >> 8;
  result[6] = ((short)a[6] * (short)b[6]) >> 8;
  result[7] = ((short)a[7] * (short)b[7]) >> 8;
  return result;
}

pv2siu
test_4 (pv2siu a, pv2siu b)
{
  pv2siu result;
  result[0] = ((unsigned long)a[0] * (unsigned long)b[0]) >> 32; 
  result[1] = ((unsigned long)a[1] * (unsigned long)b[1]) >> 32; 
  return result;
}

pv4hiu
test_5 (pv4hiu a, pv4hiu b)
{
  pv4hiu result;
  result[0] = ((unsigned int)a[0] * (unsigned int)b[0]) >> 16;
  result[1] = ((unsigned int)a[1] * (unsigned int)b[1]) >> 16;
  result[2] = ((unsigned int)a[2] * (unsigned int)b[2]) >> 16;
  result[3] = ((unsigned int)a[3] * (unsigned int)b[3]) >> 16;
  return result;
}

pv8qiu
test_6 (pv8qiu a, pv8qiu b)
{
  pv8qiu result;
  result[0] = ((unsigned short)a[0] * (unsigned short)b[0]) >> 8;
  result[1] = ((unsigned short)a[1] * (unsigned short)b[1]) >> 8;
  result[2] = ((unsigned short)a[2] * (unsigned short)b[2]) >> 8;
  result[3] = ((unsigned short)a[3] * (unsigned short)b[3]) >> 8;
  result[4] = ((unsigned short)a[4] * (unsigned short)b[4]) >> 8;
  result[5] = ((unsigned short)a[5] * (unsigned short)b[5]) >> 8;
  result[6] = ((unsigned short)a[6] * (unsigned short)b[6]) >> 8;
  result[7] = ((unsigned short)a[7] * (unsigned short)b[7]) >> 8;
  return result;
}
/* { dg-final { scan-assembler-times {\mpmulh\.w\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulh\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulh\.b\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulhu\.w\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulhu\.h\M} 1 } } */
/* { dg-final { scan-assembler-times {\mpmulhu\.b\M} 1 } } */
