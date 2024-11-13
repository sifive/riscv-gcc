#ifndef __SIFIVE_SCI_H
#define __SIFIVE_SCI_H

#if defined(__riscv_xsfsci)

#if __riscv_xlen == 32
#define __riscv_sf_sci_x_xx_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_x_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_xx32((funct3), (funct7), (x), (y));
#endif

#if __riscv_xlen == 64
#define __riscv_sf_sci_x_xx_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_x_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_xx64((funct3), (funct7), (x), (y));
#endif

#endif // defined(__riscv_xsfsci)

#endif
