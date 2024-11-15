/* { dg-do compile } */
/* { dg-options "-march=rv32gc_xsfvqmaccqoq -mabi=ilp32d -O3" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "riscv_vector.h"

/*
** foo1:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo1(vint32m1_t vd, vint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m1(vd, vs1, vs2, vl);
}

/*
** foo2:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo2(vint32m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m2(vd, vs1, vs2, vl);
}

/*
** foo3:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo3(vint32m4_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m4(vd, vs1, vs2, vl);
}

/*
** foo4:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo4(vint32m8_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m8(vd, vs1, vs2, vl);
}

/*
** foo5:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo5(vint32m1_t vd, vint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo6:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo6(vint32m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo7:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo7(vint32m4_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo8:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo8(vint32m8_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo9:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo9(vint32m1_t vd, vint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo10:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo(vint32m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo11:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo11(vint32m4_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo12:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo12(vint32m8_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo13:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo13(vint32m1_t vd, vint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_tu(vd, vs1, vs2, vl);
}

/*
** foo14:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo14(vint32m2_t vd, vint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_tu(vd, vs1, vs2, vl);
}

/*
** foo15:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo15(vint32m4_t vd, vint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_tu(vd, vs1, vs2, vl);
}

/*
** foo16:
** ...
** vsetvli\t
** sf\.vqmacc\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo16(vint32m8_t vd, vint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmacc_4x8x4_tu(vd, vs1, vs2, vl);
}

/*
** foo17:
** ...
** vsetvli\t
** sf\.vqmaccsu\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo17(vint32m1_t vd, vint8m1_t vs1, vuint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccsu_4x8x4_i32m1(vd, vs1, vs2, vl);
}

/*
** foo18:
** ...
** vsetvli\t
** sf.vqmaccu.4x8x4\t
** ...
*/

vint32m8_t foo18(vint32m8_t vd, vuint8m1_t vs1, vuint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccu_4x8x4_tu(vd, vs1, vs2, vl);
}

/*
** foo19:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo19(vint32m1_t vd, vuint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m1(vd, vs1, vs2, vl);
}

/*
** foo20:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo20(vint32m2_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m2(vd, vs1, vs2, vl);
}

/*
** foo21:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo21(vint32m4_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m4(vd, vs1, vs2, vl);
}

/*
** foo22:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo22(vint32m8_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m8(vd, vs1, vs2, vl);
}

/*
** foo23:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo23(vint32m1_t vd, vuint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo24:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo24(vint32m2_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo25:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo25(vint32m4_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo26:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo26(vint32m8_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4(vd, vs1, vs2, vl);
}

/*
** foo27:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo27(vint32m1_t vd, vuint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo28:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo28(vint32m2_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo29:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo29(vint32m4_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo30:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo30(vint32m8_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m8_tu(vd, vs1, vs2, vl);
}

/*
** foo31:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m1_t foo31(vint32m1_t vd, vuint8m1_t vs1, vint8mf2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m1_tu(vd, vs1, vs2, vl);
}

/*
** foo32:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m2_t foo32(vint32m2_t vd, vuint8m1_t vs1, vint8m1_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m2_tu(vd, vs1, vs2, vl);
}

/*
** foo33:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m4_t foo33(vint32m4_t vd, vuint8m1_t vs1, vint8m2_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m4_tu(vd, vs1, vs2, vl);
}

/*
** foo34:
** ...
** vsetvli\t
** sf\.vqmaccus\.4x8x4\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+,\s*v0.t
** ...
*/

vint32m8_t foo34(vint32m8_t vd, vuint8m1_t vs1, vint8m4_t vs2, size_t vl)
{    
    return __riscv_sf__vqmaccus_4x8x4_i32m8_tu(vd, vs1, vs2, vl);
}

