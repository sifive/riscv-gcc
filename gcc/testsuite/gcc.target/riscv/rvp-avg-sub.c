/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */

/* Test averaging subtract (both signed and unsigned) */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));
typedef unsigned char pv8uqi __attribute__((vector_size (8)));
typedef unsigned short pv4uhi __attribute__((vector_size (8)));
typedef unsigned int pv2usi __attribute__((vector_size (8)));

/* ========================================================================
   Signed Averaging Subtract
   ======================================================================== */

/* Signed averaging subtract - 8-bit */
pv8qi test_pasub_b(pv8qi a, pv8qi b) {
    return (a - b) >> 1;
}

/* Signed averaging subtract - 16-bit */
pv4hi test_pasub_h(pv4hi a, pv4hi b) {
    return (a - b) >> 1;
}

/* Signed averaging subtract - 32-bit */
pv2si test_pasub_w(pv2si a, pv2si b) {
    return (a - b) >> 1;
}

/* ========================================================================
   Unsigned Averaging Subtract
   ======================================================================== */

/* Unsigned averaging subtract - 8-bit */
pv8uqi test_pasubu_b(pv8uqi a, pv8uqi b) {
    return (a - b) >> 1;
}

/* Unsigned averaging subtract - 16-bit */
pv4uhi test_pasubu_h(pv4uhi a, pv4uhi b) {
    return (a - b) >> 1;
}

/* Unsigned averaging subtract - 32-bit */
pv2usi test_pasubu_w(pv2usi a, pv2usi b) {
    return (a - b) >> 1;
}

/* Verify that averaging subtract instructions are generated */
/* Signed averaging subtract */
/* { dg-final { scan-assembler-times {pasub\.b} 1 } } */
/* { dg-final { scan-assembler-times {pasub\.h} 1 } } */
/* { dg-final { scan-assembler-times {pasub\.w} 1 } } */

/* Unsigned averaging subtract */
/* { dg-final { scan-assembler-times {pasubu\.b} 1 } } */
/* { dg-final { scan-assembler-times {pasubu\.h} 1 } } */
/* { dg-final { scan-assembler-times {pasubu\.w} 1 } } */

