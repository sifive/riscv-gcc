/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLUI.H instruction for P-extension (RV32).
   PLUI.H loads (imm10 << 6) to all halfword positions.  */

typedef unsigned int uint32_t;

/* Valid PLUI.H patterns: (imm10 << 6) where imm10 in [-512, 511].  */
uint32_t plui_h_511 (void) { return 0x7FC07FC0U; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,511} } } */

uint32_t plui_h_16 (void) { return 0x04000400U; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,16} } } */

uint32_t plui_h_neg16 (void) { return 0xFC00FC00U; }
/* { dg-final { scan-assembler {plui\.h\t[a-x0-9]+,-16} } } */

uint32_t plui_h_510 (void) { return 0x7F807F80U; }

/* 0x80008000 = (-512 << 6) but lui is more efficient.  */
uint32_t plui_h_neg512 (void) { return 0x80008000U; }

/* Lower 6 bits not zero: should NOT use plui.h.  */
uint32_t not_plui_h_1 (void) { return 0x7FC17FC1U; }

/* PLI.H takes priority for values in [-512, 511].  */
uint32_t pli_h_priority (void) { return 0x00400040U; }

/* { dg-final { scan-assembler-times {plui\.h} 4 } } */
