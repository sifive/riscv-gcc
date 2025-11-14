/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto" } } */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* Test 8-bit shift register operand */
pv8qi test_sll_qi(pv8qi a, int b) {
    return a << b;
}

/* Test 8-bit shift immediate operand */
pv8qi test_slli_qi(pv8qi a) {
    return a << 3;
}

/* Test 16-bit shift register operand */
pv4hi test_sll_hi(pv4hi a, int b) {
    return a << b;
}

/* Test 16-bit shift immediate operand */
pv4hi test_slli_hi(pv4hi a) {
    return a << 3;
}

/* Test 32-bit shift register operand */
pv2si test_sll_wi(pv2si a, int b) {
    return a << b;
}

/* Test 32-bit shift immediate operand */
pv2si test_slli_wi(pv2si a) {
    return a << 3;
}

/* { dg-final { scan-assembler-times "psll\.bs" 1 } } */
/* { dg-final { scan-assembler-times "pslli\.b" 1 } } */
/* { dg-final { scan-assembler-times "psll\.hs" 1 } } */
/* { dg-final { scan-assembler-times "pslli\.h" 1 } } */
/* { dg-final { scan-assembler-times "psll\.ws" 1 } } */
/* { dg-final { scan-assembler-times "pslli\.w" 1 } } */
