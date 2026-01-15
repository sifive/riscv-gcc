/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLUI.H instruction for P-extension (RV64).
   PLUI.H loads (imm10 << 6) to all halfword positions.  */

typedef unsigned long long uint64_t;

/* Valid PLUI.H patterns: (imm10 << 6) where imm10 in [-512, 511].  */
uint64_t plui_h_511 (void) { return 0x7FC07FC07FC07FC0ULL; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

uint64_t plui_h_16 (void) { return 0x0400040004000400ULL; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,16} } } */

uint64_t plui_h_neg512 (void) { return 0x8000800080008000ULL; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,-512} } } */

uint64_t plui_h_510 (void) { return 0x7F807F807F807F80ULL; }
uint64_t plui_h_neg16 (void) { return 0xFC00FC00FC00FC00ULL; }

/* Lower 6 bits not zero: should NOT use plui.h.  */
uint64_t not_plui_h_1 (void) { return 0x7FC17FC17FC17FC1ULL; }

/* { dg-final { scan-assembler-times {plui\.h} 5 } } */
