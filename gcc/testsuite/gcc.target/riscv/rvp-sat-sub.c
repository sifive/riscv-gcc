/* { dg-do compile } */
/* { dg-options "-march=rv64gcp -mabi=lp64" } */
/* { dg-additional-options "-ftree-vectorize -fno-vect-cost-model" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Og" "-Oz" "-funroll-loops" } } */

/* Test saturating subtract auto-vectorization (both signed and unsigned) */

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;

#define INT8_MIN (-128)
#define INT8_MAX 127
#define INT16_MIN (-32768)
#define INT16_MAX 32767
#define INT32_MIN (-2147483648)
#define INT32_MAX 2147483647

/* ========================================================================
   Signed Saturating Subtract - 8-bit
   ======================================================================== */

/* Pattern 1: Using XOR to detect overflow */
void vec_sat_s_sub_i8_fmt_1(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t diff = (uint8_t)x - (uint8_t)y;
        out[i] = (x ^ y) >= 0
            ? diff
            : (diff ^ x) >= 0
              ? diff
              : x < 0 ? INT8_MIN : INT8_MAX;
    }
}

/* Pattern 2: Simplified overflow check */
void vec_sat_s_sub_i8_fmt_2(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t diff = (uint8_t)x - (uint8_t)y;
        out[i] = (x ^ y) >= 0 || (diff ^ x) >= 0
            ? diff
            : x < 0 ? INT8_MIN : INT8_MAX;
    }
}

/* Pattern 3: Using __builtin_sub_overflow */
void vec_sat_s_sub_i8_fmt_3(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t diff;
        int overflow = __builtin_sub_overflow(x, y, &diff);
        out[i] = overflow ? (x < 0 ? INT8_MIN : INT8_MAX) : diff;
    }
}

/* ========================================================================
   Signed Saturating Subtract - 16-bit
   ======================================================================== */

/* Pattern 1: Using XOR */
void vec_sat_s_sub_i16_fmt_1(int16_t *out, int16_t *op_1, int16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int16_t x = op_1[i];
        int16_t y = op_2[i];
        int16_t diff = (uint16_t)x - (uint16_t)y;
        out[i] = (x ^ y) >= 0
            ? diff
            : (diff ^ x) >= 0
              ? diff
              : x < 0 ? INT16_MIN : INT16_MAX;
    }
}

/* Pattern 2: Simplified */
void vec_sat_s_sub_i16_fmt_2(int16_t *out, int16_t *op_1, int16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int16_t x = op_1[i];
        int16_t y = op_2[i];
        int16_t diff = (uint16_t)x - (uint16_t)y;
        out[i] = (x ^ y) >= 0 || (diff ^ x) >= 0
            ? diff
            : x < 0 ? INT16_MIN : INT16_MAX;
    }
}

/* ========================================================================
   Signed Saturating Subtract - 32-bit
   ======================================================================== */

/* Pattern 1: Using __builtin_sub_overflow (simpler, less likely to crash) */
void vec_sat_s_sub_i32_fmt_1(int32_t *out, int32_t *op_1, int32_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int32_t x = op_1[i];
        int32_t y = op_2[i];
        int32_t diff;
        int overflow = __builtin_sub_overflow(x, y, &diff);
        out[i] = overflow ? (x < 0 ? INT32_MIN : INT32_MAX) : diff;
    }
}

/* ========================================================================
   Unsigned Saturating Subtract - 8-bit
   ======================================================================== */

/* Pattern 1: Bitwise AND with mask */
void vec_sat_u_sub_u8_fmt_1(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = (x - y) & (-(uint8_t)(x >= y));
    }
}

/* Pattern 2: Ternary operator */
void vec_sat_u_sub_u8_fmt_2(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = x >= y ? x - y : 0;
    }
}

/* Pattern 3: Inverted ternary */
void vec_sat_u_sub_u8_fmt_3(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = x < y ? 0 : x - y;
    }
}

/* ========================================================================
   Unsigned Saturating Subtract - 16-bit
   ======================================================================== */

/* Pattern 1: Bitwise AND */
void vec_sat_u_sub_u16_fmt_1(uint16_t *out, uint16_t *op_1, uint16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint16_t x = op_1[i];
        uint16_t y = op_2[i];
        out[i] = (x - y) & (-(uint16_t)(x >= y));
    }
}

/* Pattern 2: Ternary operator */
void vec_sat_u_sub_u16_fmt_2(uint16_t *out, uint16_t *op_1, uint16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint16_t x = op_1[i];
        uint16_t y = op_2[i];
        out[i] = x >= y ? x - y : 0;
    }
}

/* ========================================================================
   Unsigned Saturating Subtract - 32-bit
   ======================================================================== */

/* Pattern 1: Bitwise AND */
void vec_sat_u_sub_u32_fmt_1(uint32_t *out, uint32_t *op_1, uint32_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint32_t x = op_1[i];
        uint32_t y = op_2[i];
        out[i] = (x - y) & (-(uint32_t)(x >= y));
    }
}

/* Verify that saturating subtract instructions are generated */
/* Signed saturating subtract */
/* { dg-final { scan-assembler-times {\mpssub\.b\M} 3 } } */
/* { dg-final { scan-assembler-times {\mpssub\.h\M} 2 } } */
/* { dg-final { scan-assembler-times {\mpssub\.w\M} 1 } } */

/* Unsigned saturating subtract */
/* { dg-final { scan-assembler-times {\mpssubu\.b\M} 3 } } */
/* { dg-final { scan-assembler-times {\mpssubu\.h\M} 2 } } */
/* { dg-final { scan-assembler-times {\mpssubu\.w\M} 1 } } */

