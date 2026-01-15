/* { dg-do compile } */
/* { dg-require-effective-target rv32 } */
/* { dg-options "-march=rv32gcp0p15 -mabi=ilp32 -O2" } */

/* Test PLI.H instruction for P-extension (RV32).
   PLI.H broadcasts a 10-bit signed immediate [-512, 511] to all halfwords.  */

typedef unsigned int uint32_t;

/* Replicated halfword constants in range [-512, 511].  */
uint32_t pli_h_42 (void) { return 0x00420042U; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,66} } } */

uint32_t pli_h_1ff (void) { return 0x01FF01FFU; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,511} } } */

uint32_t pli_h_fe00 (void) { return 0xFE00FE00U; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,-512} } } */

uint32_t pli_h_1 (void) { return 0x00010001U; }
uint32_t pli_h_ff (void) { return 0x00FF00FFU; }
uint32_t pli_h_ff00 (void) { return 0xFF00FF00U; }
uint32_t pli_h_fffe (void) { return 0xFFFEFFFEU; }

/* Not replicated: should NOT use pli.h or plui.h.  */
uint32_t not_pli_h_diff (void) { return 0x00420043U; }

/* PLI.B takes priority for replicated bytes.  */
uint32_t pli_b_priority (void) { return 0x00000000U; }

/* { dg-final { scan-assembler-times {pli\.h} 7 } } */
