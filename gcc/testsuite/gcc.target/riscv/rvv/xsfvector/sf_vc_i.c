/* { dg-do compile } */
/* { dg-options "-march=rv64gcv_xsfvcp -mabi=lp64d -O3" } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "riscv_vector.h"


/*
** test_sf_vc_v_i_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_i_u8mf8(size_t vl) {
    return __riscv_sf_vc_v_i_u8mf8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_i_se_u8mf8(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8mf8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_i_u8mf4(size_t vl) {
    return __riscv_sf_vc_v_i_u8mf4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_i_se_u8mf4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8mf4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_i_u8mf2(size_t vl) {
    return __riscv_sf_vc_v_i_u8mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_i_se_u8mf2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_i_u8m1(size_t vl) {
    return __riscv_sf_vc_v_i_u8m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_i_se_u8m1(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_i_u8m2(size_t vl) {
    return __riscv_sf_vc_v_i_u8m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_i_se_u8m2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_i_u8m4(size_t vl) {
    return __riscv_sf_vc_v_i_u8m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_i_se_u8m4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_i_u8m8(size_t vl) {
    return __riscv_sf_vc_v_i_u8m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_i_se_u8m8(size_t vl) {
    return __riscv_sf_vc_v_i_se_u8m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_i_u16mf4(size_t vl) {
    return __riscv_sf_vc_v_i_u16mf4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_i_se_u16mf4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16mf4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_i_u16mf2(size_t vl) {
    return __riscv_sf_vc_v_i_u16mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_i_se_u16mf2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_i_u16m1(size_t vl) {
    return __riscv_sf_vc_v_i_u16m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_i_se_u16m1(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_i_u16m2(size_t vl) {
    return __riscv_sf_vc_v_i_u16m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_i_se_u16m2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_i_u16m4(size_t vl) {
    return __riscv_sf_vc_v_i_u16m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_i_se_u16m4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_i_u16m8(size_t vl) {
    return __riscv_sf_vc_v_i_u16m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_i_se_u16m8(size_t vl) {
    return __riscv_sf_vc_v_i_se_u16m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_i_u32mf2(size_t vl) {
    return __riscv_sf_vc_v_i_u32mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_i_se_u32mf2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u32mf2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_i_u32m1(size_t vl) {
    return __riscv_sf_vc_v_i_u32m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_i_se_u32m1(size_t vl) {
    return __riscv_sf_vc_v_i_se_u32m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_i_u32m2(size_t vl) {
    return __riscv_sf_vc_v_i_u32m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_i_se_u32m2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u32m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_i_u32m4(size_t vl) {
    return __riscv_sf_vc_v_i_u32m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_i_se_u32m4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u32m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_i_u32m8(size_t vl) {
    return __riscv_sf_vc_v_i_u32m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_i_se_u32m8(size_t vl) {
    return __riscv_sf_vc_v_i_se_u32m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_i_u64m1(size_t vl) {
    return __riscv_sf_vc_v_i_u64m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_i_se_u64m1(size_t vl) {
    return __riscv_sf_vc_v_i_se_u64m1(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_i_u64m2(size_t vl) {
    return __riscv_sf_vc_v_i_u64m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_i_se_u64m2(size_t vl) {
    return __riscv_sf_vc_v_i_se_u64m2(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_i_u64m4(size_t vl) {
    return __riscv_sf_vc_v_i_u64m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_i_se_u64m4(size_t vl) {
    return __riscv_sf_vc_v_i_se_u64m4(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_i_u64m8(size_t vl) {
    return __riscv_sf_vc_v_i_u64m8(1, 2, 4, vl);
}

/*
** test_sf_vc_v_i_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.i\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_i_se_u64m8(size_t vl) {
    return __riscv_sf_vc_v_i_se_u64m8(1, 2, 4, vl);
}


/*
** test_sf_vc_i_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8mf8(size_t vl) {
    __riscv_sf_vc_i_se_u8mf8(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8mf4(size_t vl) {
    __riscv_sf_vc_i_se_u8mf4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8mf2(size_t vl) {
    __riscv_sf_vc_i_se_u8mf2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8m1(size_t vl) {
    __riscv_sf_vc_i_se_u8m1(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8m2(size_t vl) {
    __riscv_sf_vc_i_se_u8m2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8m4(size_t vl) {
    __riscv_sf_vc_i_se_u8m4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u8m8(size_t vl) {
    __riscv_sf_vc_i_se_u8m8(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16mf4(size_t vl) {
    __riscv_sf_vc_i_se_u16mf4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16mf2(size_t vl) {
    __riscv_sf_vc_i_se_u16mf2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16m1(size_t vl) {
    __riscv_sf_vc_i_se_u16m1(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16m2(size_t vl) {
    __riscv_sf_vc_i_se_u16m2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16m4(size_t vl) {
    __riscv_sf_vc_i_se_u16m4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u16m8(size_t vl) {
    __riscv_sf_vc_i_se_u16m8(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u32mf2(size_t vl) {
    __riscv_sf_vc_i_se_u32mf2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u32m1(size_t vl) {
    __riscv_sf_vc_i_se_u32m1(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u32m2(size_t vl) {
    __riscv_sf_vc_i_se_u32m2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u32m4(size_t vl) {
    __riscv_sf_vc_i_se_u32m4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u32m8(size_t vl) {
    __riscv_sf_vc_i_se_u32m8(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u64m1(size_t vl) {
    __riscv_sf_vc_i_se_u64m1(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u64m2(size_t vl) {
    __riscv_sf_vc_i_se_u64m2(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u64m4(size_t vl) {
    __riscv_sf_vc_i_se_u64m4(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_i_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.i\t[0-9]+,[0-9]+,[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_i_se_u64m8(size_t vl) {
    __riscv_sf_vc_i_se_u64m8(1, 2, 3, 4, vl);
}

/*
** test_sf_vc_v_iv_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_iv_u8mf8(vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8mf8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_iv_se_u8mf8(vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8mf8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_iv_u8mf4(vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8mf4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_iv_se_u8mf4(vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8mf4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_iv_u8mf2(vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_iv_se_u8mf2(vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_iv_u8m1(vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_iv_se_u8m1(vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_iv_u8m2(vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_iv_se_u8m2(vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_iv_u8m4(vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_iv_se_u8m4(vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_iv_u8m8(vuint8m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u8m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_iv_se_u8m8(vuint8m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u8m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_iv_u16mf4(vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16mf4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_iv_se_u16mf4(vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16mf4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_iv_u16mf2(vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_iv_se_u16mf2(vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_iv_u16m1(vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_iv_se_u16m1(vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_iv_u16m2(vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_iv_se_u16m2(vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_iv_u16m4(vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_iv_se_u16m4(vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_iv_u16m8(vuint16m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u16m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_iv_se_u16m8(vuint16m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u16m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_iv_u32mf2(vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u32mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_iv_se_u32mf2(vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u32mf2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_iv_u32m1(vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u32m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_iv_se_u32m1(vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u32m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_iv_u32m2(vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u32m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_iv_se_u32m2(vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u32m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_iv_u32m4(vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u32m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_iv_se_u32m4(vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u32m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_iv_u32m8(vuint32m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u32m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_iv_se_u32m8(vuint32m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u32m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_iv_u64m1(vuint64m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u64m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_iv_se_u64m1(vuint64m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u64m1(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_iv_u64m2(vuint64m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u64m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_iv_se_u64m2(vuint64m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u64m2(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_iv_u64m4(vuint64m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u64m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_iv_se_u64m4(vuint64m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u64m4(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_iv_u64m8(vuint64m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_u64m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_v_iv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.iv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_iv_se_u64m8(vuint64m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_iv_se_u64m8(1, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8mf8(vuint8mf8_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8mf8(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8mf4(vuint8mf4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8mf4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8mf2(vuint8mf2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8mf2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8m1(vuint8m1_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8m1(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8m2(vuint8m2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8m2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8m4(vuint8m4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8m4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u8m8(vuint8m8_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u8m8(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16mf4(vuint16mf4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16mf4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16mf2(vuint16mf2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16mf2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16m1(vuint16m1_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16m1(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16m2(vuint16m2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16m2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16m4(vuint16m4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16m4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u16m8(vuint16m8_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u16m8(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u32mf2(vuint32mf2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u32mf2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u32m1(vuint32m1_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u32m1(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u32m2(vuint32m2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u32m2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u32m4(vuint32m4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u32m4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u32m8(vuint32m8_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u32m8(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u64m1(vuint64m1_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u64m1(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u64m2(vuint64m2_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u64m2(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u64m4(vuint64m4_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u64m4(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_iv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.iv\t[0-9]+,[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_iv_se_u64m8(vuint64m8_t vs2, size_t vl) {
    __riscv_sf_vc_iv_se_u64m8(1, 3, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_ivv_u8mf8(vuint8mf8_t vd, vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf8_t test_sf_vc_v_ivv_se_u8mf8(vuint8mf8_t vd, vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_ivv_u8mf4(vuint8mf4_t vd, vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf4_t test_sf_vc_v_ivv_se_u8mf4(vuint8mf4_t vd, vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_ivv_u8mf2(vuint8mf2_t vd, vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8mf2_t test_sf_vc_v_ivv_se_u8mf2(vuint8mf2_t vd, vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_ivv_u8m1(vuint8m1_t vd, vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m1_t test_sf_vc_v_ivv_se_u8m1(vuint8m1_t vd, vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_ivv_u8m2(vuint8m2_t vd, vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m2_t test_sf_vc_v_ivv_se_u8m2(vuint8m2_t vd, vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_ivv_u8m4(vuint8m4_t vd, vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m4_t test_sf_vc_v_ivv_se_u8m4(vuint8m4_t vd, vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_ivv_u8m8(vuint8m8_t vd, vuint8m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u8m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint8m8_t test_sf_vc_v_ivv_se_u8m8(vuint8m8_t vd, vuint8m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u8m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_ivv_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_ivv_se_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_ivv_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_ivv_se_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_ivv_u16m1(vuint16m1_t vd, vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_ivv_se_u16m1(vuint16m1_t vd, vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_ivv_u16m2(vuint16m2_t vd, vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_ivv_se_u16m2(vuint16m2_t vd, vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_ivv_u16m4(vuint16m4_t vd, vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_ivv_se_u16m4(vuint16m4_t vd, vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_ivv_u16m8(vuint16m8_t vd, vuint16m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u16m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_ivv_se_u16m8(vuint16m8_t vd, vuint16m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u16m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_ivv_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_ivv_se_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_ivv_u32m1(vuint32m1_t vd, vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_ivv_se_u32m1(vuint32m1_t vd, vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_ivv_u32m2(vuint32m2_t vd, vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_ivv_se_u32m2(vuint32m2_t vd, vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_ivv_u32m4(vuint32m4_t vd, vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u32m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_ivv_se_u32m4(vuint32m4_t vd, vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u32m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_ivv_u32m8(vuint32m8_t vd, vuint32m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u32m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_ivv_se_u32m8(vuint32m8_t vd, vuint32m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u32m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_ivv_u64m1(vuint64m1_t vd, vuint64m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u64m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_ivv_se_u64m1(vuint64m1_t vd, vuint64m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u64m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_ivv_u64m2(vuint64m2_t vd, vuint64m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u64m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_ivv_se_u64m2(vuint64m2_t vd, vuint64m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u64m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_ivv_u64m4(vuint64m4_t vd, vuint64m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u64m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_ivv_se_u64m4(vuint64m4_t vd, vuint64m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u64m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_ivv_u64m8(vuint64m8_t vd, vuint64m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_u64m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.v\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_ivv_se_u64m8(vuint64m8_t vd, vuint64m8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivv_se_u64m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8mf8(vuint8mf8_t vd, vuint8mf8_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8mf4(vuint8mf4_t vd, vuint8mf4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8mf2(vuint8mf2_t vd, vuint8mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8m1(vuint8m1_t vd, vuint8m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8m2(vuint8m2_t vd, vuint8m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8m4(vuint8m4_t vd, vuint8m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u8m8:
** ...
** vsetivli\s+zero+,0+,e8+,m8,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u8m8(vuint8m8_t vd, vuint8m8_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u8m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16mf4(vuint16mf4_t vd, vuint16mf4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16mf2(vuint16mf2_t vd, vuint16mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16m1(vuint16m1_t vd, vuint16m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16m2(vuint16m2_t vd, vuint16m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16m4(vuint16m4_t vd, vuint16m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u16m8:
** ...
** vsetivli\s+zero+,0+,e16+,m8,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u16m8(vuint16m8_t vd, vuint16m8_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u16m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u32mf2(vuint32mf2_t vd, vuint32mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u32m1(vuint32m1_t vd, vuint32m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u32m2(vuint32m2_t vd, vuint32m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u32m4(vuint32m4_t vd, vuint32m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u32m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u32m8:
** ...
** vsetivli\s+zero+,0+,e32+,m8,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u32m8(vuint32m8_t vd, vuint32m8_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u32m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u64m1:
** ...
** vsetivli\s+zero+,0+,e64+,m1,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u64m1(vuint64m1_t vd, vuint64m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u64m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u64m2:
** ...
** vsetivli\s+zero+,0+,e64+,m2,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u64m2(vuint64m2_t vd, vuint64m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u64m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u64m4:
** ...
** vsetivli\s+zero+,0+,e64+,m4,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u64m4(vuint64m4_t vd, vuint64m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u64m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivv_se_u64m8:
** ...
** vsetivli\s+zero+,0+,e64+,m8,ta,ma+
** sf\.vc\.ivv\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivv_se_u64m8(vuint64m8_t vd, vuint64m8_t vs2, size_t vl) {
    __riscv_sf_vc_ivv_se_u64m8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_ivw_u8mf8(vuint16mf4_t vd, vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf4_t test_sf_vc_v_ivw_se_u8mf8(vuint16mf4_t vd, vuint8mf8_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_ivw_u8mf4(vuint16mf2_t vd, vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16mf2_t test_sf_vc_v_ivw_se_u8mf4(vuint16mf2_t vd, vuint8mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_ivw_u8mf2(vuint16m1_t vd, vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m1_t test_sf_vc_v_ivw_se_u8mf2(vuint16m1_t vd, vuint8mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_ivw_u8m1(vuint16m2_t vd, vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m2_t test_sf_vc_v_ivw_se_u8m1(vuint16m2_t vd, vuint8m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_ivw_u8m2(vuint16m4_t vd, vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m4_t test_sf_vc_v_ivw_se_u8m2(vuint16m4_t vd, vuint8m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_ivw_u8m4(vuint16m8_t vd, vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint16m8_t test_sf_vc_v_ivw_se_u8m4(vuint16m8_t vd, vuint8m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_ivw_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32mf2_t test_sf_vc_v_ivw_se_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_ivw_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m1_t test_sf_vc_v_ivw_se_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_ivw_u16m1(vuint32m2_t vd, vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m2_t test_sf_vc_v_ivw_se_u16m1(vuint32m2_t vd, vuint16m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_ivw_u16m2(vuint32m4_t vd, vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m4_t test_sf_vc_v_ivw_se_u16m2(vuint32m4_t vd, vuint16m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_ivw_u16m4(vuint32m8_t vd, vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint32m8_t test_sf_vc_v_ivw_se_u16m4(vuint32m8_t vd, vuint16m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_ivw_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m1_t test_sf_vc_v_ivw_se_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_ivw_u32m1(vuint64m2_t vd, vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m2_t test_sf_vc_v_ivw_se_u32m1(vuint64m2_t vd, vuint32m1_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/

vuint64m4_t test_sf_vc_v_ivw_u32m2(vuint64m4_t vd, vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m4_t test_sf_vc_v_ivw_se_u32m2(vuint64m4_t vd, vuint32m2_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_ivw_u32m4(vuint64m8_t vd, vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_u32m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_v_ivw_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.v\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
vuint64m8_t test_sf_vc_v_ivw_se_u32m4(vuint64m8_t vd, vuint32m4_t vs2, size_t vl) {
    return __riscv_sf_vc_v_ivw_se_u32m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8mf8:
** ...
** vsetivli\s+zero+,0+,e8+,mf8,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8mf8(vuint16mf4_t vd, vuint8mf8_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8mf8(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8mf4:
** ...
** vsetivli\s+zero+,0+,e8+,mf4,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8mf4(vuint16mf2_t vd, vuint8mf4_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8mf2:
** ...
** vsetivli\s+zero+,0+,e8+,mf2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8mf2(vuint16m1_t vd, vuint8mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8m1:
** ...
** vsetivli\s+zero+,0+,e8+,m1,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8m1(vuint16m2_t vd, vuint8m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8m2:
** ...
** vsetivli\s+zero+,0+,e8+,m2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8m2(vuint16m4_t vd, vuint8m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u8m4:
** ...
** vsetivli\s+zero+,0+,e8+,m4,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u8m4(vuint16m8_t vd, vuint8m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u8m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u16mf4:
** ...
** vsetivli\s+zero+,0+,e16+,mf4,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u16mf4(vuint32mf2_t vd, vuint16mf4_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u16mf4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u16mf2:
** ...
** vsetivli\s+zero+,0+,e16+,mf2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u16mf2(vuint32m1_t vd, vuint16mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u16mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u16m1:
** ...
** vsetivli\s+zero+,0+,e16+,m1,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u16m1(vuint32m2_t vd, vuint16m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u16m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u16m2:
** ...
** vsetivli\s+zero+,0+,e16+,m2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u16m2(vuint32m4_t vd, vuint16m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u16m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u16m4:
** ...
** vsetivli\s+zero+,0+,e16+,m4,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u16m4(vuint32m8_t vd, vuint16m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u16m4(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u32mf2:
** ...
** vsetivli\s+zero+,0+,e32+,mf2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u32mf2(vuint64m1_t vd, vuint32mf2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u32mf2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u32m1:
** ...
** vsetivli\s+zero+,0+,e32+,m1,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u32m1(vuint64m2_t vd, vuint32m1_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u32m1(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u32m2:
** ...
** vsetivli\s+zero+,0+,e32+,m2,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u32m2(vuint64m4_t vd, vuint32m2_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u32m2(1, vd, vs2, 4, vl);
}

/*
** test_sf_vc_ivw_se_u32m4:
** ...
** vsetivli\s+zero+,0+,e32+,m4,ta,ma+
** sf\.vc\.ivw\t[0-9]+,v[0-9]+,v[0-9]+,[0-9]+
** ...
*/
void test_sf_vc_ivw_se_u32m4(vuint64m8_t vd, vuint32m4_t vs2, size_t vl) {
    __riscv_sf_vc_ivw_se_u32m4(1, vd, vs2, 4, vl);
}

