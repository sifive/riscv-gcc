/* { dg-do compile } */
/* { dg-options "-march=rv64im_xsfmm64a64f0p6 -mabi=lp64 -mcmodel=medlow -Wno-riscv-implicit-extension-version" } */

int main () {

#ifndef __riscv_arch_test
#error "__riscv_arch_test"
#endif

#if __riscv_xlen != 64
#error "__riscv_xlen"
#endif

#if !defined(__riscv_i)
#error "__riscv_i"
#endif

#if !defined(__riscv_f)
#error "__riscv_f"
#endif

#if !defined(__riscv_zicsr)
#error "__riscv_zicsr"
#endif

#if !defined(__riscv_zve32f)
#error "__riscv_zve32f"
#endif

#if !defined(__riscv_zve32x)
#error "__riscv_zve32x"
#endif

#if !defined(__riscv_zve64d)
#error "__riscv_zve64d"
#endif

#if !defined(__riscv_zve64f)
#error "__riscv_zve64f"
#endif

#if !defined(__riscv_zve64x)
#error "__riscv_zve64x"
#endif

#if !defined(__riscv_zvl32b)
#error "__riscv_zvl32b"
#endif

#if !defined(__riscv_zvl64b)
#error "__riscv_zvl64b"
#endif

#if !defined(__riscv_xsfmm64a64f)
#error "__riscv_xsfmm64a64f"
#endif

#if !defined(__riscv_xsfmmbase)
#error "__riscv_xsfmmbase"
#endif

  return 0;
}
