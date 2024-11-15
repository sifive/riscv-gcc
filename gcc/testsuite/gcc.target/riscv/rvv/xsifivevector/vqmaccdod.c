/* { dg-do compile } */
/* { dg-options "-march=rv32gc_xsfvqmaccdod -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "riscv_vector.h"

/*
** foo1:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo1(vint32m1_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m1(vd, vs1, vs2, vl);
}

/*
** foo2:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo2(vint32m2_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m2(vd, vs1, vs2, vl);
}

/*
** foo3:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo3(vint32m4_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m4(vd, vs1, vs2, vl);
}

/*
** foo4:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo4(vint32m8_t vd, vint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m8(vd, vs1, vs2, vl);
}

/*
** foo5:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo5(vint32m1_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo6:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo6(vint32m2_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo7:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo7(vint32m4_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo8:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo8(vint32m8_t vd, vint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo9:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo9(vint32m1_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo10:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo10(vint32m2_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo11:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo11(vint32m4_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo12:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo12(vint32m8_t vd, vint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo13(vint32m1_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo14:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo14(vint32m2_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo15:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo15(vint32m4_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo16:
** ...
** vsetvli\t
** sf\.vqmacc\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo16(vint32m8_t vd, vint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmacc_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo17:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo17(vint32m1_t vd, vint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m1(vd, vs1, vs2, vl);
}

/*
** foo18:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo18(vint32m2_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m2(vd, vs1, vs2, vl);
}

/*
** foo19:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo19(vint32m4_t vd, vint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m4(vd, vs1, vs2, vl);
}

/*
** foo20:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo20(vint32m8_t vd, vint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m8(vd, vs1, vs2, vl);
}

/*
** foo21:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo21(vint32m1_t vd, vint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo22:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo22(vint32m2_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo23:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo23(vint32m4_t vd, vint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo24:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo24(vint32m8_t vd, vint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo25:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo25(vint32m1_t vd, vint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo26:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

void foo26(vint32m2_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl)
 foo26(vint32m2_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo27:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo27(vint32m4_t vd, vint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo28:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo28(vint32m8_t vd, vint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo29:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo29(vint32m1_t vd, vint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo30:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo30(vint32m2_t vd, vint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo31:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo31(vint32m4_t vd, vint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo32:
** ...
** vsetvli\t
** sf\.vqmaccsu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo32(vint32m8_t vd, vint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccsu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo33:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo33(vint32m1_t vd, vuint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m1(vd, vs1, vs2, vl);
}

/*
** foo34:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo34(vint32m2_t vd, vuint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m2(vd, vs1, vs2, vl);
}

/*
** foo35:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo35(vint32m4_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m4(vd, vs1, vs2, vl);
}

/*
** foo36:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo36(vint32m8_t vd, vuint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m8(vd, vs1, vs2, vl);
}

/*
** foo37:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo37(vint32m1_t vd, vuint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo38:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo38(vint32m2_t vd, vuint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo39:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo39(vint32m4_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo40:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo40(vint32m8_t vd, vuint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo41:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo41(vint32m1_t vd, vuint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo42:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo42(vint32m2_t vd, vuint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo43:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo43(vint32m4_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo44:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo44(vint32m8_t vd, vuint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo45:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo45(vint32m1_t vd, vuint8m1_t vs1, vuint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo46:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo46(vint32m2_t vd, vuint8m1_t vs1, vuint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo47:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo47(vint32m4_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo48:
** ...
** vsetvli\t
** sf\.vqmaccu\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo48(vint32m8_t vd, vuint8m1_t vs1, vuint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccu_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo49:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo49(vint32m1_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m1(vd, vs1, vs2, vl);
}

/*
** foo50:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo50(vint32m2_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m2(vd, vs1, vs2, vl);
}

/*
** foo51:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo51(vint32m4_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m4(vd, vs1, vs2, vl);
}

/*
** foo52:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo52(vint32m8_t vd, vuint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m8(vd, vs1, vs2, vl);
}

/*
** foo53:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo53(vint32m1_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo54:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo54(vint32m2_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo55:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo55(vint32m4_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo56:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo56(vint32m8_t vd, vuint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2(vd, vs1, vs2, vl);
}

/*
** foo57:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo57(vint32m1_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo58:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo58(vint32m2_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo59:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo59(vint32m4_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo60:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo60(vint32m8_t vd, vuint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo61:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo61(vint32m1_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo62:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo62(vint32m2_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo63:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo63(vint32m4_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_tu(vd, vs1, vs2, vl);
}

/*
** foo64:
** ...
** vsetvli\t
** sf\.vqmaccus\.2x8x2\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo64(vint32m8_t vd, vuint8m1_t vs1, vint8m8_t vs2, size_t vl)
{    
    return __riscv_sf_vqmaccus_2x8x2_tu(vd, vs1, vs2, vl);
}
