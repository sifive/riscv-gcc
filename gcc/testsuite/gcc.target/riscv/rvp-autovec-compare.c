/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64 -O2" } */

/* Test auto-vectorization of RVP comparison operations.
   This tests that all comparison operators are correctly synthesized
   from RVP's base instructions (pmseq, pmslt, pmsltu) using NOT and
   argument swapping.  */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef unsigned char pv8uqi __attribute__((vector_size (8)));

/* Signed comparisons */

pv8qi test_eq(pv8qi a, pv8qi b) {
    return a == b;
}

pv8qi test_ne(pv8qi a, pv8qi b) {
    /* Use bitwise NOT on comparison result to get != */
    pv8qi eq = a == b;
    return ~eq;
}

pv8qi test_lt(pv8qi a, pv8qi b) {
    return a < b;
}

pv8qi test_le(pv8qi a, pv8qi b) {
    return a <= b;
}

pv8qi test_gt(pv8qi a, pv8qi b) {
    return a > b;
}

pv8qi test_ge(pv8qi a, pv8qi b) {
    return a >= b;
}

/* Unsigned comparisons */

pv8uqi test_ltu(pv8uqi a, pv8uqi b) {
    return a < b;
}

pv8uqi test_leu(pv8uqi a, pv8uqi b) {
    return a <= b;
}

pv8uqi test_gtu(pv8uqi a, pv8uqi b) {
    return a > b;
}

pv8uqi test_geu(pv8uqi a, pv8uqi b) {
    return a >= b;
}

/* Verify instruction counts:
   - pmseq.b: 2 times (EQ, NE)
   - pmslt.b: 4 times (LT, LE, GT, GE)
   - pmsltu.b: 4 times (LTU, LEU, GTU, GEU)
   - not: 5 times (NE, LE, GE, LEU, GEU) */
/* { dg-final { scan-assembler-times "\\tpmseq\\.b\\t" 2 } } */
/* { dg-final { scan-assembler-times "\\tpmslt\\.b\\t" 4 } } */
/* { dg-final { scan-assembler-times "\\tpmsltu\\.b\\t" 4 } } */
/* { dg-final { scan-assembler-times "\\tnot\\t" 5 } } */

