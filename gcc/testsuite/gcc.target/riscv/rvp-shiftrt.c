/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef signed short pv4hi __attribute__((vector_size (8)));
typedef signed int pv2si __attribute__((vector_size (8)));

typedef unsigned char pvu8qi __attribute__((vector_size (8)));
typedef unsigned short pvu4hi __attribute__((vector_size (8)));
typedef unsigned int pvu2si __attribute__((vector_size (8)));

/* Test 8-bit arithmetic right shift */
pv8qi test_sra_qi(pv8qi a, int b) {
    return a >> b;
}

/* Test 8-bit arithmetic immediate right shift */
pv8qi test_srai_qi(pv8qi a) {
    return a >> 1;
}

/* Test 16-bit arithmetic right shift */
pv4hi test_sra_hi(pv4hi a, int b) {
    return a >> b;
}

/* Test 16-bit arithmetic immediate right shift */
pv4hi test_srai_hi(pv4hi a) {
    return a >> 3;
}

/* Test 32-bit arithmetic right shift */
pv2si test_sra_si(pv2si a, int b) {
    return a >> b;
}

/* Test 32-bit arithmetic immediate right shift */
pv2si test_srai_si(pv2si a) {
    return a >> 3;
}

/* Test 8-bit logical right shift */
pvu8qi test_srl_qi(pvu8qi a, int b) {
    return a >> b;
}

/* Test 8-bit logical immediate right shift */
pvu8qi test_srli_qi(pvu8qi a) {
    return a >> 3;
}

/* Test 16-bit logical right shift */
pvu4hi test_srl_hi(pvu4hi a, int b) {
    return a >> b;
}

/* Test 16-bit logical immediate right shift */
pvu4hi test_srli_hi(pvu4hi a) {
    return a >> 3;
}

/* Test 32-bit logical right shift */
pvu2si test_srl_si(pvu2si a, int b) {
    return a >> b;
}

/* Test 32-bit logical immediate right shift */
pvu2si test_srli_si(pvu2si a) {
    return a >> 3;
}

/* { dg-final { scan-assembler-times "psra\.bs" 1 } } */
/* { dg-final { scan-assembler-times "psrai\.b" 1 } } */
/* { dg-final { scan-assembler-times "psra\.hs" 1 } } */
/* { dg-final { scan-assembler-times "psrai\.h" 1 } } */
/* { dg-final { scan-assembler-times "psra\.ws" 1 } } */
/* { dg-final { scan-assembler-times "psrai\.w" 1 } } */
/* { dg-final { scan-assembler-times "psrl\.bs" 1 } } */
/* { dg-final { scan-assembler-times "psrli\.b" 1 } } */
/* { dg-final { scan-assembler-times "psrl\.hs" 1 } } */
/* { dg-final { scan-assembler-times "psrli\.h" 1 } } */
/* { dg-final { scan-assembler-times "psrl\.ws" 1 } } */
/* { dg-final { scan-assembler-times "psrli\.w" 1 } } */

