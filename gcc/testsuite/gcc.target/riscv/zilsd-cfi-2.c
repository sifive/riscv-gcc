/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zilsd -mabi=ilp32 -fomit-frame-pointer -funwind-tables" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-O1" "-g" "-Oz" "-Os" "-flto" } } */

/* Test CFI (Call Frame Information) for multiple Zilsd register pairs.
   This verifies that DWARF unwinding information is correct when
   multiple even-odd register pairs are saved/restored with sd/ld.  */

extern void bar (void);

void foo (void)
{
  asm volatile (";my clobber list"
		: : : "s0", "s1", "s2", "s3", "s4", "s5");
  bar ();
  asm volatile (";my clobber list"
		: : : "s0", "s1", "s2", "s3", "s4", "s5");
}

/* Check that sd is used for all three pairs.  */
/* { dg-final { scan-assembler-times "sd\ts0," 1 } } */
/* { dg-final { scan-assembler-times "sd\ts2," 1 } } */
/* { dg-final { scan-assembler-times "sd\ts4," 1 } } */

/* Check CFI offset directives for all registers.
   The exact offsets depend on the stack layout, but all registers
   should have .cfi_offset directives.  */
/* { dg-final { scan-assembler ".cfi_offset 1," } } */
/* { dg-final { scan-assembler ".cfi_offset 8," } } */
/* { dg-final { scan-assembler ".cfi_offset 9," } } */
/* { dg-final { scan-assembler ".cfi_offset 18," } } */
/* { dg-final { scan-assembler ".cfi_offset 19," } } */
/* { dg-final { scan-assembler ".cfi_offset 20," } } */
/* { dg-final { scan-assembler ".cfi_offset 21," } } */

/* Check CFI restore directives for all registers.  */
/* { dg-final { scan-assembler ".cfi_restore 1" } } */
/* { dg-final { scan-assembler ".cfi_restore 8" } } */
/* { dg-final { scan-assembler ".cfi_restore 9" } } */
/* { dg-final { scan-assembler ".cfi_restore 18" } } */
/* { dg-final { scan-assembler ".cfi_restore 19" } } */
/* { dg-final { scan-assembler ".cfi_restore 20" } } */
/* { dg-final { scan-assembler ".cfi_restore 21" } } */

