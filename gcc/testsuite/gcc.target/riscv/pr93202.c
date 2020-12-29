/* PR inline-asm/93202 */
/* { dg-do compile { target fpic } } */
/* { dg-options "-fpic -mcmodel=medlow" } */

void
foo (void)
{
  asm volatile ("%h0" :: "i" (&foo));	/* { dg-error "invalid use of '%h'" } */
  asm volatile ("%R0" :: "i" (&foo));	/* { dg-error "invalid use of '%R'" } */
}
