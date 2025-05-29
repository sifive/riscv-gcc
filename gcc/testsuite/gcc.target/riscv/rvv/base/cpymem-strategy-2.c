/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gcv -mabi=ilp32d -mstringop-strategy=scalar" } */
/* { dg-skip-if "RV32 is incompatible with compact code model" { *-*-* } { "-mcmodel=compact" } { "" } } */

#include "cpymem-strategy.h"

/* { dg-final { scan-assembler-times {call\tmemcpy} 1 } } */
