#include "riscv_vector.h"

vint32m1_t test1(vint32m1_t vd, vint8m1_t vs1, vint8mf2_t vs2, size_t vl) {
        return __riscv_sf_vqmacc_4x8x4_i32m1(vd, vs1, vs2, vl);
}

vint32m2_t test2(vint32m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl) {
        return __riscv_sf_vqmacc_4x8x4_i32m2(vd, vs1, vs2, vl);
}

vint32m4_t test3(vint32m4_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl) {
        return __riscv_sf_vqmacc_4x8x4_i32m4(vd, vs1, vs2, vl);
}

vint32m8_t test4(vint32m8_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl) {
        return __riscv_sf_vqmacc_4x8x4_i32m8(vd, vs1, vs2, vl);
}
