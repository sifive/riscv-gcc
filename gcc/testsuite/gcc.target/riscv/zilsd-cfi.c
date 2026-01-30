/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer -funwind-tables" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os" "-flto" } } */

/* Test that Zilsd generates correct CFI (Call Frame Information) for
   DWARF unwinding.  When using sd/ld to save/restore register pairs,
   the CFI must correctly describe the location of each register.

   For Zilsd sd s0, offset(sp):
   - s0 (x8) is stored at offset
   - s1 (x9) is stored at offset + 4

   The CFI should have:
   - .cfi_offset 8, <offset from CFA for s0>
   - .cfi_offset 9, <offset from CFA for s1>
   - .cfi_restore 8
   - .cfi_restore 9  */

extern void bar (void);

void foo (void)
{
  asm volatile (";my clobber list"
		: : : "s0", "s1");
  bar ();
  asm volatile (";my clobber list"
		: : : "s0", "s1");
}

/* Check that sd is used for the s0-s1 pair.  */
/* { dg-final { scan-assembler-times "sd\ts0," 1 } } */
/* { dg-final { scan-assembler-times "ld\ts0," 1 } } */

/* Check CFI offset directives for both registers.
   The exact offsets depend on the stack layout, but both s0 (x8)
   and s1 (x9) should have .cfi_offset directives.  */
/* { dg-final { scan-assembler ".cfi_offset 8," } } */
/* { dg-final { scan-assembler ".cfi_offset 9," } } */

/* Check CFI restore directives for both registers.  */
/* { dg-final { scan-assembler ".cfi_restore 8" } } */
/* { dg-final { scan-assembler ".cfi_restore 9" } } */

/* Check that ra also has correct CFI.  */
/* { dg-final { scan-assembler ".cfi_offset 1," } } */
/* { dg-final { scan-assembler ".cfi_restore 1" } } */

