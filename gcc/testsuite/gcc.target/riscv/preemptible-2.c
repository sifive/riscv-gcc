/* Verify that all temp regs saved for call.  */
/* { dg-do compile } */
/* { dg-options "-O" } */
extern int vector_10 (void);

void __attribute__ ((interrupt ("SiFive-CLIC-preemptible")))
sub (void)
{
  vector_10 ();
}
/* { dg-final { scan-assembler-times "s\[wd\]\t\[at\]\[0-7\]" 15 } } */
