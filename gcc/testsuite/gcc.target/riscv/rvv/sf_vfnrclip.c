#include "riscv_vector.h"

vint8mf8_t test1(float vs1, vfloat32mf2_t vs2, size_t vl) {
        return  __riscv_sf_vfnrclip_x_f_qf_i8mf8(vs2, vs1, vl);
}

vint8mf4_t test2(float vs1, vfloat32m1_t vs2, size_t vl) {
        return  __riscv_sf_vfnrclip_x_f_qf_i8mf4(vs2, vs1, vl);
}

vint8mf2_t test2(float vs1, vfloat32m2_t vs2, size_t vl) {
        return  __riscv_sf_vfnrclip_x_f_qf_i8mf2(vs2, vs1, vl);
}

vint8m1_t test2(float vs1, vfloat32m4_t vs2, size_t vl) {
        return  __riscv_sf_vfnrclip_x_f_qf_i8m1(vs2, vs1, vl);
}

vint8m2_t test2(float vs1, vfloat32m8_t vs2, size_t vl) {
        return  __riscv_sf_vfnrclip_x_f_qf_i8m2(vs2, vs1, vl);
}
