/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */

/* Test auto-vectorization of vcond_mask pattern.
   This tests the optimization of VEC_COND_EXPR for RVP vectors.  */

typedef signed char pv8qi __attribute__((vector_size (8)));

/* Test identity case: mask ? -1 : 0
   The comparison already returns the correct format, so vcond_mask
   should optimize to just returning the mask.  */
pv8qi test_vcond_identity(pv8qi a, pv8qi b) {
    return a == b;
}

/* Test inverted case: mask ? 0 : -1
   vcond_mask should optimize to NOT of the mask.  */
pv8qi test_vcond_inverted(pv8qi a, pv8qi b) {
    pv8qi mask = a == b;
    return ~mask;
}

/* Test combining multiple comparisons with AND.  */
pv8qi test_comparison_chain(pv8qi a, pv8qi b, pv8qi c, pv8qi d) {
    pv8qi mask1 = a == b;
    pv8qi mask2 = c < d;
    return mask1 & mask2;
}

/* Test combining multiple comparisons with OR.  */
pv8qi test_comparison_or(pv8qi a, pv8qi b, pv8qi c, pv8qi d) {
    pv8qi mask1 = a == b;
    pv8qi mask2 = c < d;
    return mask1 | mask2;
}

/* Verify instruction counts */
/* { dg-final { scan-assembler-times "\\tpmseq\\.b\\t" 4 } } */
/* { dg-final { scan-assembler-times "\\tpmslt\\.b\\t" 2 } } */
/* { dg-final { scan-assembler-times "\\tand\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tor\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tnot\\t" 1 } } */

