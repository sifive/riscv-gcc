/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLI.H instruction for P-extension (RV64).
   PLI.H broadcasts a 10-bit signed immediate [-512, 511] to all halfwords.  */

typedef unsigned long long uint64_t;

/* Replicated halfword constants in range [-512, 511].  */
uint64_t pli_h_42 (void) { return 0x0042004200420042ULL; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,66} } } */

uint64_t pli_h_1ff (void) { return 0x01FF01FF01FF01FFULL; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,511} } } */

uint64_t pli_h_fe00 (void) { return 0xFE00FE00FE00FE00ULL; }
/* { dg-final { scan-assembler {pli\.h\t[a-x0-9]+,-512} } } */

uint64_t pli_h_1 (void) { return 0x0001000100010001ULL; }
uint64_t pli_h_ff (void) { return 0x00FF00FF00FF00FFULL; }
uint64_t pli_h_ff00 (void) { return 0xFF00FF00FF00FF00ULL; }
uint64_t pli_h_fffe (void) { return 0xFFFEFFFEFFFEFFFEULL; }

/* Not replicated: should NOT use pli.h or plui.h.  */
uint64_t not_pli_h_diff (void) { return 0x0042004200420043ULL; }

/* { dg-final { scan-assembler-times {pli\.h} 7 } } */
