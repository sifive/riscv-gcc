/* { dg-do compile } */

#include <riscv_vector.h>
#include <stddef.h>
#include "rvv-common.h"

/* Takes the scalar type STYPE, vector class VCLASS (int or float), and
   the e and m value.  */
#define VSLOADSTORE(STYPE, VCLASST, VCLASS, EM, MLEN, STYPEC, SEW)                                   \
  void vsloadstore##VCLASS##EM(size_t n, long stride, STYPE *x,                \
                               STYPE *y, STYPE z) {                            \
    v##VCLASST##EM##_t vx, vy, vz;                                            \
    vbool##MLEN##_t mask;                                                    \
    mask = MSET (MLEN);                                             \
    vx = VLOAD(VCLASS, SEW, EM, x);                                               \
    vy = VLOAD(VCLASS, SEW, EM, y);                                               \
    vz = vx + vy;                                                              \
    vsse##SEW##_v_##VCLASS##EM##_m(mask, x, stride, vz);                          \
  }

RVV_INT_TEST(VSLOADSTORE)
RVV_UINT_TEST(VSLOADSTORE)
RVV_FLOAT_TEST(VSLOADSTORE)

/* { dg-final { scan-assembler-times "vsse8.v" 8 } } */
/* { dg-final { scan-assembler-times "vsse16.v" 12 } } */
/* { dg-final { scan-assembler-times "vsse32.v" 12 } } */
/* { dg-final { scan-assembler-times "vsse64.v" 12 } } */
