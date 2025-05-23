#ifndef __SIFIVE_SCI_H
#define __SIFIVE_SCI_H

#if defined(__riscv_xsfsci)

#if __riscv_xlen == 32
/* R-Type */
#define __riscv_sf_sci_0_r_x_xx_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_0_r_x_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_0_r_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_x_xx_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_x_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_x_xx_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_x_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_x_xx_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_x_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_x_xx32((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_xx_se_32(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_xx32((funct3), (funct7), (x), (y));

/* I-Type */
#define __riscv_sf_sci_0_i_x_xi_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_0_i_x_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_0_i_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_x_xi_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_x_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_x_xi_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_x_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_x_xi_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_x_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_x_xi32((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_xi_se_32(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_xi32((funct3), (rs1), (uimm12));

/* U-Type */
#define __riscv_sf_sci_0_u_x_i_32(uimm20) \
  __builtin_riscv_sf_sci_0_u_x_i32((uimm20));

#define __riscv_sf_sci_0_u_x_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_0_u_x_i32((uimm20));

#define __riscv_sf_sci_0_u_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_0_u_i32((uimm20));

#define __riscv_sf_sci_1_u_x_i_32(uimm20) \
  __builtin_riscv_sf_sci_1_u_x_i32((uimm20));

#define __riscv_sf_sci_1_u_x_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_1_u_x_i32((uimm20));

#define __riscv_sf_sci_1_u_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_1_u_i32((uimm20));

#define __riscv_sf_sci_2_u_x_i_32(uimm20) \
  __builtin_riscv_sf_sci_2_u_x_i32((uimm20));

#define __riscv_sf_sci_2_u_x_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_2_u_x_i32((uimm20));

#define __riscv_sf_sci_2_u_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_2_u_i32((uimm20));

#define __riscv_sf_sci_3_u_x_i_32(uimm20) \
  __builtin_riscv_sf_sci_3_u_x_i32((uimm20));

#define __riscv_sf_sci_3_u_x_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_3_u_x_i32((uimm20));

#define __riscv_sf_sci_3_u_i_se_32(uimm20) \
  __builtin_riscv_sf_sci_3_u_i32((uimm20));

/* X-Type */
#define __riscv_sf_sci_0_x_i_se_32(uimm25) \
  __builtin_riscv_sf_sci_0_x_i32((uimm25));

#define __riscv_sf_sci_1_x_i_se_32(uimm25) \
  __builtin_riscv_sf_sci_1_x_i32((uimm25));

#define __riscv_sf_sci_2_x_i_se_32(uimm25) \
  __builtin_riscv_sf_sci_2_x_i32((uimm25));

#define __riscv_sf_sci_3_x_i_se_32(uimm25) \
  __builtin_riscv_sf_sci_3_x_i32((uimm25));
#endif

#if __riscv_xlen == 64
/* R-Type */
#define __riscv_sf_sci_0_r_x_xx_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_0_r_x_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_0_r_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_0_r_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_x_xx_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_x_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_1_r_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_1_r_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_x_xx_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_x_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_2_r_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_2_r_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_x_xx_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_x_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_x_xx64((funct3), (funct7), (x), (y));

#define __riscv_sf_sci_3_r_xx_se_64(funct3, funct7, x, y) \
  __builtin_riscv_sf_sci_3_r_xx64((funct3), (funct7), (x), (y));

/* I-Type */
#define __riscv_sf_sci_0_i_x_xi_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_0_i_x_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_0_i_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_0_i_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_x_xi_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_x_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_1_i_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_1_i_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_x_xi_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_x_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_2_i_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_2_i_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_x_xi_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_x_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_x_xi64((funct3), (rs1), (uimm12));

#define __riscv_sf_sci_3_i_xi_se_64(funct3, rs1, uimm12) \
  __builtin_riscv_sf_sci_3_i_xi64((funct3), (rs1), (uimm12));

/* U-Type */
#define __riscv_sf_sci_0_u_x_i_64(uimm20) \
  __builtin_riscv_sf_sci_0_u_x_i64((uimm20));

#define __riscv_sf_sci_0_u_x_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_0_u_x_i64((uimm20));

#define __riscv_sf_sci_0_u_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_0_u_i64((uimm20));

#define __riscv_sf_sci_1_u_x_i_64(uimm20) \
  __builtin_riscv_sf_sci_1_u_x_i64((uimm20));

#define __riscv_sf_sci_1_u_x_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_1_u_x_i64((uimm20));

#define __riscv_sf_sci_1_u_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_1_u_i64((uimm20));

#define __riscv_sf_sci_2_u_x_i_64(uimm20) \
  __builtin_riscv_sf_sci_2_u_x_i64((uimm20));

#define __riscv_sf_sci_2_u_x_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_2_u_x_i64((uimm20));

#define __riscv_sf_sci_2_u_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_2_u_i64((uimm20));

#define __riscv_sf_sci_3_u_x_i_64(uimm20) \
  __builtin_riscv_sf_sci_3_u_x_i64((uimm20));

#define __riscv_sf_sci_3_u_x_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_3_u_x_i64((uimm20));

#define __riscv_sf_sci_3_u_i_se_64(uimm20) \
  __builtin_riscv_sf_sci_3_u_i64((uimm20));

/* X-Type */
#define __riscv_sf_sci_0_x_i_se_64(uimm25) \
  __builtin_riscv_sf_sci_0_x_i64((uimm25));

#define __riscv_sf_sci_1_x_i_se_64(uimm25) \
  __builtin_riscv_sf_sci_1_x_i64((uimm25));

#define __riscv_sf_sci_2_x_i_se_64(uimm25) \
  __builtin_riscv_sf_sci_2_x_i64((uimm25));

#define __riscv_sf_sci_3_x_i_se_64(uimm25) \
  __builtin_riscv_sf_sci_3_x_i64((uimm25));
#endif

#endif // defined(__riscv_xsfsci)

#endif
