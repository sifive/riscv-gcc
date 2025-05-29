/* { dg-do compile } */
/* { dg-options "-march=rv32gc_zve32f_zvfh -mabi=ilp32f -O3" } */
/* { dg-skip-if "RV32 is incompatible with compact code model" { *-*-* } { "-mcmodel=compact" } { "" } } */

#include "pr110299-1.h"

/* { dg-final { scan-assembler-times {vfwredosum\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 1 } } */
/* { dg-final { scan-assembler-times {vfwredusum\.vs\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+} 1 } } */
