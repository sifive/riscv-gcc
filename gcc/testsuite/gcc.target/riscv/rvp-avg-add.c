/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */

/* Test averaging add (both signed and unsigned) */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));
typedef unsigned char pv8uqi __attribute__((vector_size (8)));
typedef unsigned short pv4uhi __attribute__((vector_size (8)));
typedef unsigned int pv2usi __attribute__((vector_size (8)));

/* ========================================================================
   Signed Averaging Add
   ======================================================================== */

/* Signed averaging add - 8-bit */
pv8qi test_paadd_b(pv8qi a, pv8qi b) {
    return (a + b) >> 1;
}

/* Signed averaging add - 16-bit */
pv4hi test_paadd_h(pv4hi a, pv4hi b) {
    return (a + b) >> 1;
}

/* Signed averaging add - 32-bit */
pv2si test_paadd_w(pv2si a, pv2si b) {
    return (a + b) >> 1;
}

/* ========================================================================
   Unsigned Averaging Add
   ======================================================================== */

/* Unsigned averaging add - 8-bit */
pv8uqi test_paaddu_b(pv8uqi a, pv8uqi b) {
    return (a + b) >> 1;
}

/* Unsigned averaging add - 16-bit */
pv4uhi test_paaddu_h(pv4uhi a, pv4uhi b) {
    return (a + b) >> 1;
}

/* Unsigned averaging add - 32-bit */
pv2usi test_paaddu_w(pv2usi a, pv2usi b) {
    return (a + b) >> 1;
}

/* Verify that averaging add instructions are generated */
/* Signed averaging add */
/* { dg-final { scan-assembler-times {paadd\.b} 1 } } */
/* { dg-final { scan-assembler-times {paadd\.h} 1 } } */
/* { dg-final { scan-assembler-times {paadd\.w} 1 } } */

/* Unsigned averaging add */
/* { dg-final { scan-assembler-times {paaddu\.b} 1 } } */
/* { dg-final { scan-assembler-times {paaddu\.h} 1 } } */
/* { dg-final { scan-assembler-times {paaddu\.w} 1 } } */

