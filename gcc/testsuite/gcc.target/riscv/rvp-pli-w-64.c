/* { dg-do compile } */
/* { dg-require-effective-target rv64 } */
/* { dg-options "-march=rv64gcp0p15 -mabi=lp64 -O2" } */

/* Test PLI.W instruction for P-extension (RV64 only).
   PLI.W broadcasts a 10-bit signed immediate [-512, 511] to all words.  */

typedef unsigned long long uint64_t;

/* Replicated word constants in range [-512, 511].  */
uint64_t pli_w_42 (void) { return 0x0000004200000042ULL; }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,66} } } */

uint64_t pli_w_1ff (void) { return 0x000001FF000001FFULL; }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,511} } } */

uint64_t pli_w_fe00 (void) { return 0xFFFFFE00FFFFFE00ULL; }
/* { dg-final { scan-assembler {pli\.w\t[a-x0-9]+,-512} } } */

uint64_t pli_w_1 (void) { return 0x0000000100000001ULL; }
uint64_t pli_w_ff00 (void) { return 0xFFFFFF00FFFFFF00ULL; }
uint64_t pli_w_fffe (void) { return 0xFFFFFFFEFFFFFFFEULL; }

/* Not replicated: should NOT use pli.w or plui.w.  */
uint64_t not_pli_w_diff (void) { return 0x0000004200000043ULL; }

/* { dg-final { scan-assembler-times {pli\.w} 6 } } */
