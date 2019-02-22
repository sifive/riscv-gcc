/* Verify that csr instructions are not emitted.  */
/* { dg-do compile } */
/* { dg-options "-O" } */

void __attribute__ ((interrupt ("SiFive-CLIC-preemptible")))
sub (void)
{
}
/* { dg-final { scan-assembler-times "mcause" 2 } } */
/* { dg-final { scan-assembler-times "mepc" 2 } } */
/* { dg-final { scan-assembler-times "mstatus" 2 } } */
