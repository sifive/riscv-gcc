/* Verify that csr instructions emitted.  */
/* { dg-do compile } */
/* { dg-options "-O" } */
extern int interrupt_count;

void __attribute__ ((interrupt ("SiFive-CLIC-preemptible")))
sub (void)
{
  interrupt_count++;
}
/* { dg-final { scan-assembler-times "csr\[rw\]" 6 } } */
