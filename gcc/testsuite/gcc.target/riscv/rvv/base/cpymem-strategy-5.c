/* { dg-do compile } */
/* { dg-options "-march=rv32gc -mabi=ilp32d -mstringop-strategy=vector" } */
/* { dg-skip-if "RV32 is incompatible with compact code model" { *-*-* } { "-mcmodel=compact" } { "" } } */

#include "cpymem-strategy.h"

/* { dg-final { scan-assembler-times {call\tmemcpy} 2 } } */
