/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zve32f_zvfh -mabi=ilp32f -O3" } */
/* { dg-skip-if "RV32 is incompatible with compact code model" { *-*-* } { "-mcmodel=compact" } { "" } } */

#include "pr110277-1.h"

/* { dg-final { scan-assembler-times {vfredmax\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
/* { dg-final { scan-assembler-times {vfredmin\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
/* { dg-final { scan-assembler-times {vfredosum\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
/* { dg-final { scan-assembler-times {vfredusum\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 2 } } */
