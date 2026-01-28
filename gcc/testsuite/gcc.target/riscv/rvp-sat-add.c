/* { dg-do compile } */
/* { dg-options "-march=rv64gcp0p19 -mabi=lp64" } */
/* { dg-additional-options "-ftree-vectorize -fno-vect-cost-model" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-Os" "-Og" "-Oz" "-funroll-loops" } } */

/* Test saturating add auto-vectorization (both signed and unsigned) */

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
   Signed Saturating Add - 8-bit
   ======================================================================== */

/* Pattern 1: Using XOR to detect overflow */
void vec_sat_s_add_i8_fmt_1(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t sum = (uint8_t)x + (uint8_t)y;
        out[i] = (x ^ y) < 0
            ? sum
            : (sum ^ x) >= 0
              ? sum
              : x < 0 ? INT8_MIN : INT8_MAX;
    }
}

/* Pattern 2: Simplified overflow check */
void vec_sat_s_add_i8_fmt_2(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t sum = (uint8_t)x + (uint8_t)y;
        if ((x ^ y) < 0 || (sum ^ x) >= 0)
            out[i] = sum;
        else
            out[i] = x < 0 ? INT8_MIN : INT8_MAX;
    }
}

/* Pattern 3: Using __builtin_add_overflow */
void vec_sat_s_add_i8_fmt_3(int8_t *out, int8_t *op_1, int8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int8_t x = op_1[i];
        int8_t y = op_2[i];
        int8_t sum;
        int overflow = __builtin_add_overflow(x, y, &sum);
        out[i] = overflow ? (x < 0 ? INT8_MIN : INT8_MAX) : sum;
    }
}

/* ========================================================================
   Signed Saturating Add - 16-bit
   ======================================================================== */

/* Pattern 1: Using XOR */
void vec_sat_s_add_i16_fmt_1(int16_t *out, int16_t *op_1, int16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int16_t x = op_1[i];
        int16_t y = op_2[i];
        int16_t sum = (uint16_t)x + (uint16_t)y;
        out[i] = (x ^ y) < 0
            ? sum
            : (sum ^ x) >= 0
              ? sum
              : x < 0 ? INT16_MIN : INT16_MAX;
    }
}

/* Pattern 2: Simplified */
void vec_sat_s_add_i16_fmt_2(int16_t *out, int16_t *op_1, int16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int16_t x = op_1[i];
        int16_t y = op_2[i];
        int16_t sum = (uint16_t)x + (uint16_t)y;
        if ((x ^ y) < 0 || (sum ^ x) >= 0)
            out[i] = sum;
        else
            out[i] = x < 0 ? INT16_MIN : INT16_MAX;
    }
}

/* ========================================================================
   Signed Saturating Add - 32-bit
   ======================================================================== */

/* Pattern 1: Using __builtin_add_overflow (simpler, less likely to crash) */
void vec_sat_s_add_i32_fmt_1(int32_t *out, int32_t *op_1, int32_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        int32_t x = op_1[i];
        int32_t y = op_2[i];
        int32_t sum;
        int overflow = __builtin_add_overflow(x, y, &sum);
        out[i] = overflow ? (x < 0 ? INT32_MIN : INT32_MAX) : sum;
    }
}

/* ========================================================================
   Unsigned Saturating Add - 8-bit
   ======================================================================== */

/* Pattern 1: Bitwise OR with overflow check */
void vec_sat_u_add_u8_fmt_1(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = (x + y) | (-(uint8_t)((uint8_t)(x + y) < x));
    }
}

/* Pattern 2: Ternary operator with overflow check */
void vec_sat_u_add_u8_fmt_2(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = (uint8_t)(x + y) >= x ? (x + y) : (uint8_t)-1;
    }
}

/* Pattern 3: Inverted ternary */
void vec_sat_u_add_u8_fmt_3(uint8_t *out, uint8_t *op_1, uint8_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint8_t x = op_1[i];
        uint8_t y = op_2[i];
        out[i] = (uint8_t)(x + y) < x ? (uint8_t)-1 : (x + y);
    }
}

/* ========================================================================
   Unsigned Saturating Add - 16-bit
   ======================================================================== */

/* Pattern 1: Bitwise OR */
void vec_sat_u_add_u16_fmt_1(uint16_t *out, uint16_t *op_1, uint16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint16_t x = op_1[i];
        uint16_t y = op_2[i];
        out[i] = (x + y) | (-(uint16_t)((uint16_t)(x + y) < x));
    }
}

/* Pattern 2: Ternary operator */
void vec_sat_u_add_u16_fmt_2(uint16_t *out, uint16_t *op_1, uint16_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint16_t x = op_1[i];
        uint16_t y = op_2[i];
        out[i] = (uint16_t)(x + y) >= x ? (x + y) : (uint16_t)-1;
    }
}

/* ========================================================================
   Unsigned Saturating Add - 32-bit
   ======================================================================== */

/* Pattern 1: Bitwise OR */
void vec_sat_u_add_u32_fmt_1(uint32_t *out, uint32_t *op_1, uint32_t *op_2, unsigned limit) {
    unsigned i;
    for (i = 0; i < limit; i++) {
        uint32_t x = op_1[i];
        uint32_t y = op_2[i];
        out[i] = (x + y) | (-(uint32_t)((uint32_t)(x + y) < x));
    }
}

/* Verify that saturating add instructions are generated */
/* Signed saturating add */
/* { dg-final { scan-assembler-times {\mpsadd\.b\M} 3 } } */
/* { dg-final { scan-assembler-times {\mpsadd\.h\M} 2 } } */
/* { dg-final { scan-assembler-times {\mpsadd\.w\M} 1 } } */

/* Unsigned saturating add */
/* { dg-final { scan-assembler-times {\mpsaddu\.b\M} 3 } } */
/* { dg-final { scan-assembler-times {\mpsaddu\.h\M} 2 } } */
/* { dg-final { scan-assembler-times {\mpsaddu\.w\M} 1 } } */

