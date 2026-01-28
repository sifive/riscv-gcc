/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64 -O2" } */

/* Test auto-vectorization for all RVP vector modes on RV64.

   This specifically tests the riscv_get_mask_mode target hook, which
   determines the mask mode for vector comparisons. For RVP, the mask
   mode should be the same as the data mode (e.g., PV8QI comparisons
   return PV8QI masks with all-1s or all-0s).

   This tests that comparison operations work correctly for different
   element sizes:
   - PV8QI (8 x signed char, 8 bytes) → pmseq.b, pmslt.b
   - PV4HI (4 x short, 8 bytes) → pmseq.h, pmslt.h
   - PV2SI (2 x int, 8 bytes) → pmseq.w, pmslt.w

   Note: PV4QI and PV2HI are only available on RV32.  */

typedef signed char pv8qi __attribute__((vector_size (8)));
typedef short pv4hi __attribute__((vector_size (8)));
typedef int pv2si __attribute__((vector_size (8)));

/* PV8QI tests - byte operations */

pv8qi test_eq_pv8qi(pv8qi a, pv8qi b) {
    return a == b;
}

pv8qi test_lt_pv8qi(pv8qi a, pv8qi b) {
    return a < b;
}

/* PV4HI tests - halfword operations */

pv4hi test_eq_pv4hi(pv4hi a, pv4hi b) {
    return a == b;
}

pv4hi test_lt_pv4hi(pv4hi a, pv4hi b) {
    return a < b;
}

/* PV2SI tests - word operations */

pv2si test_eq_pv2si(pv2si a, pv2si b) {
    return a == b;
}

pv2si test_lt_pv2si(pv2si a, pv2si b) {
    return a < b;
}

/* Verify instruction counts for different element sizes.
   This verifies that riscv_get_mask_mode correctly returns the same
   mode for RVP vectors, allowing the correct instruction suffix to be
   selected (.b for byte, .h for halfword, .w for word).  */
/* { dg-final { scan-assembler-times "\\tpmseq\\.b\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tpmseq\\.h\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tpmseq\\.w\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tpmslt\\.b\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tpmslt\\.h\\t" 1 } } */
/* { dg-final { scan-assembler-times "\\tpmslt\\.w\\t" 1 } } */

