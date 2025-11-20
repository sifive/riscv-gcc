/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */

/* Test auto-vectorization of RVP bitwise operations.
   This tests that vector bitwise operations (AND, OR, XOR, NOT)
   are correctly mapped to scalar RISC-V instructions.  */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* AND tests - 3 modes (PV8QI, PV4HI, PV2SI) */
pv8qi test_and_qi(pv8qi a, pv8qi b) {
    return a & b;
}

pv4hi test_and_hi(pv4hi a, pv4hi b) {
    return a & b;
}

pv2si test_and_si(pv2si a, pv2si b) {
    return a & b;
}

/* OR tests - 3 modes */
pv8qi test_or_qi(pv8qi a, pv8qi b) {
    return a | b;
}

pv4hi test_or_hi(pv4hi a, pv4hi b) {
    return a | b;
}

pv2si test_or_si(pv2si a, pv2si b) {
    return a | b;
}

/* XOR tests - 3 modes */
pv8qi test_xor_qi(pv8qi a, pv8qi b) {
    return a ^ b;
}

pv4hi test_xor_hi(pv4hi a, pv4hi b) {
    return a ^ b;
}

pv2si test_xor_si(pv2si a, pv2si b) {
    return a ^ b;
}

/* NOT tests - 3 modes */
pv8qi test_not_qi(pv8qi a) {
    return ~a;
}

pv4hi test_not_hi(pv4hi a) {
    return ~a;
}

pv2si test_not_si(pv2si a) {
    return ~a;
}

/* Verify instruction counts */
/* { dg-final { scan-assembler-times "\\tand\\t" 3 } } */
/* { dg-final { scan-assembler-times "\\tor\\t" 3 } } */
/* { dg-final { scan-assembler-times "\\txor\\t" 3 } } */
/* { dg-final { scan-assembler-times "\\tnot\\t" 3 } } */

