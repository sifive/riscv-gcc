/* Test RISC-V Zicfilp non-local goto LPAD.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O2 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=none -fcf-protection=branch" } */
/* { dg-skip-if "" { *-*-* } { "-O0" "-g" "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

extern void do_something (void);

/*
** outer_function:
**	lpad	\d+
**	...
*/
void outer_function (void *label_addr)
{
  __label__ target_label;

  if (label_addr)
    goto *label_addr;

  do_something ();

target_label:
  do_something ();

  outer_function (&&target_label);
}

