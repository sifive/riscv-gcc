/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_xsfvcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "riscv_vector.h"

typedef _Float16 float16_t;
typedef float float32_t;
typedef double float64_t;

/*
** test_sf_vc_v_fv_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_fv_u16mf4(vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16mf4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_fv_se_u16mf4(vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16mf4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_fv_u16mf2(vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16mf2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_fv_se_u16mf2(vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16mf2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_fv_u16m1(vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_fv_se_u16m1(vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_fv_u16m2(vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_fv_se_u16m2(vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_fv_u16m4(vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_fv_se_u16m4(vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_fv_u16m8(vuint16m8_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u16m8(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_fv_se_u16m8(vuint16m8_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u16m8(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fv_u32mf2(vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u32mf2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fv_se_u32mf2(vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u32mf2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fv_u32m1(vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u32m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fv_se_u32m1(vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u32m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fv_u32m2(vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u32m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fv_se_u32m2(vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u32m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fv_u32m4(vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u32m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fv_se_u32m4(vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u32m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fv_u32m8(vuint32m8_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u32m8(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fv_se_u32m8(vuint32m8_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u32m8(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fv_u64m1(vuint64m1_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u64m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fv_se_u64m1(vuint64m1_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u64m1(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fv_u64m2(vuint64m2_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u64m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fv_se_u64m2(vuint64m2_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u64m2(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fv_u64m4(vuint64m4_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u64m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fv_se_u64m4(vuint64m4_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_se_u64m4(1, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fv_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.fv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_fv_u64m8(vuint64m8_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fv_u64m8(1, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16mf4(vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16mf4(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16mf2(vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16mf2(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16m1(vuint16m1_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16m1(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16m2(vuint16m2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16m2(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16m4(vuint16m4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16m4(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u16m8(vuint16m8_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u16m8(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u32mf2(vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u32mf2(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u32m1(vuint32m1_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u32m1(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u32m2(vuint32m2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u32m2(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u32m4(vuint32m4_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u32m4(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u32m8(vuint32m8_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u32m8(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u64m1(vuint64m1_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u64m1(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u64m2(vuint64m2_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u64m2(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u64m4(vuint64m4_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u64m4(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_fv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.fv\t[0-9]+,[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fv_se_u64m8(vuint64m8_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fv_se_u64m8(1, 3, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_fvv_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_fvv_se_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_fvv_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_fvv_se_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_fvv_u16m1(vuint16m1_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_fvv_se_u16m1(vuint16m1_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_fvv_u16m2(vuint16m2_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_fvv_se_u16m2(vuint16m2_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_fvv_u16m4(vuint16m4_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_fvv_se_u16m4(vuint16m4_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_fvv_u16m8(vuint16m8_t vd, vuint16m8_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u16m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_fvv_se_u16m8(vuint16m8_t vd, vuint16m8_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u16m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fvv_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fvv_se_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fvv_u32m1(vuint32m1_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fvv_se_u32m1(vuint32m1_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fvv_u32m2(vuint32m2_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fvv_se_u32m2(vuint32m2_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fvv_u32m4(vuint32m4_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u32m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fvv_se_u32m4(vuint32m4_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u32m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fvv_u32m8(vuint32m8_t vd, vuint32m8_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u32m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fvv_se_u32m8(vuint32m8_t vd, vuint32m8_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u32m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fvv_u64m1(vuint64m1_t vd, vuint64m1_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u64m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fvv_se_u64m1(vuint64m1_t vd, vuint64m1_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u64m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fvv_u64m2(vuint64m2_t vd, vuint64m2_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u64m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fvv_se_u64m2(vuint64m2_t vd, vuint64m2_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u64m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fvv_u64m4(vuint64m4_t vd, vuint64m4_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u64m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fvv_se_u64m4(vuint64m4_t vd, vuint64m4_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u64m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_fvv_u64m8(vuint64m8_t vd, vuint64m8_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_u64m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_fvv_se_u64m8(vuint64m8_t vd, vuint64m8_t vs2, float64_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvv_se_u64m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16m1(vuint16m1_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16m2(vuint16m2_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16m4(vuint16m4_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u16m8(vuint16m8_t vd, vuint16m8_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u16m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u32m1(vuint32m1_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u32m2(vuint32m2_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u32m4(vuint32m4_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u32m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u32m8(vuint32m8_t vd, vuint32m8_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u32m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u64m1(vuint64m1_t vd, vuint64m1_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u64m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u64m2(vuint64m2_t vd, vuint64m2_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u64m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u64m4(vuint64m4_t vd, vuint64m4_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u64m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.fvv\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvv_se_u64m8(vuint64m8_t vd, vuint64m8_t vs2, float64_t fs1, size_t vl) {
    __riscv_sf_vc_fvv_se_u64m8(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fvw_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_fvw_se_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fvw_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_fvw_se_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fvw_u16m1(vuint32m2_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_fvw_se_u16m1(vuint32m2_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fvw_u16m2(vuint32m4_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_fvw_se_u16m2(vuint32m4_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fvw_u16m4(vuint32m8_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_fvw_se_u16m4(vuint32m8_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fvw_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_fvw_se_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fvw_u32m1(vuint64m2_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_fvw_se_u32m1(vuint64m2_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fvw_u32m2(vuint64m4_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_fvw_se_u32m2(vuint64m4_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_fvw_u32m4(vuint64m8_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_u32m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_v_fvw_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_fvw_se_u32m4(vuint64m8_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    return __riscv_sf_vc_v_fvw_se_u32m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u16mf4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u16mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u16m1(vuint32m2_t vd, vuint16m1_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u16m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u16m2(vuint32m4_t vd, vuint16m2_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u16m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u16m4(vuint32m8_t vd, vuint16m4_t vs2, float16_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u16m4(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u32mf2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u32m1(vuint64m2_t vd, vuint32m1_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u32m1(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u32m2(vuint64m4_t vd, vuint32m2_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u32m2(1, vd, vs2, fs1, vl);
}

/*
** test_sf_vc_fvw_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.fvw\t[0-9]+,v[0-9]+,v[0-9]+,fa[0-9]+
** ...
*/
void test_sf_vc_fvw_se_u32m4(vuint64m8_t vd, vuint32m4_t vs2, float32_t fs1, size_t vl) {
    __riscv_sf_vc_fvw_se_u32m4(1, vd, vs2, fs1, vl);
}

