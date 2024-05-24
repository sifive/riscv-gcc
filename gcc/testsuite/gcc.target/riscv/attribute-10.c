/* { dg-do compile } */
/* { dg-options "-march=rv32i -march=rv32im_svnapot_unexpectedstring -mabi=ilp32" } */
int foo()
{
}
/* { dg-error "'-march=rv32im_svnapot_unexpectedstring': unsupported extension 'u'" "" { target { "riscv*-*-*" } } 0 } */
/* { dg-error "extension 'u' is unsupported standard single letter extension" "" { target { "riscv*-*-*" } } 0 } */
/* { dg-error "'-march=rv32im_svnapot_unexpectedstring': unsupported extension 'n'" "" { target { "riscv*-*-*" } } 0 } */
/* { dg-error "extension 'n' is unsupported standard single letter extension" "" { target { "riscv*-*-*" } } 0 } */
/* { dg-error "i, e or g must be the first extension" "" { target { "riscv*-*-*" } } 0 } */
