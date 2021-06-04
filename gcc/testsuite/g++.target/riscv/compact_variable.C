/* { dg-do run } */
/* { dg-options "-O2 -march=rv64imafdc_zba_zbb -mabi=lp64d -mcmodel=compact" } */

static void
init_var(void)
{
  extern int var;
  var = 15;
}

int var = 12;

static int
test(void)
{
  init_var();
  return (var == 15);
}

int main ()
{
  int result;
  result = test();

  if (result)
    return 0;
  else
    return 1;
}
