/* Verify that stack swapping instructions are emitted.  */
/* { dg-do compile } */
/* { dg-options "-O" } */
void __attribute__ ((interrupt ("SiFive-CLIC-stack-swap")))
foo2 (void)
{
  extern volatile int INTERRUPT_FLAG;
  INTERRUPT_FLAG = 0;

  extern volatile int COUNTER;
#ifdef __riscv_atomic
  __atomic_fetch_add (&COUNTER, 1, __ATOMIC_RELAXED);
#else
  COUNTER++;
#endif
}
/* { dg-final { scan-assembler-times "mscratchcsw" 2 } } */
