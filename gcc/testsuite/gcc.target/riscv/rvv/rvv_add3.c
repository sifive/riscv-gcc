/* { dg-do compile } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

RVV_INT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, add)
RVV_UINT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_IMM_MASKED_TEST, add)
RVV_FLOAT_TEST_ARG(RVV_BIN_BUILTIN_VEC_SCALAR_MASKED_TEST, fadd)

/* { dg-final { scan-assembler-times "vadd.vv" 32 } } */
/* { dg-final { scan-assembler-times "vadd.vx" 32 } } */
/* { dg-final { scan-assembler-times "vadd.vi" 32 } } */
/* { dg-final { scan-assembler-times "vfadd.vv" 12 } } */
/* { dg-final { scan-assembler-times "vfadd.vf" 12 } } */
