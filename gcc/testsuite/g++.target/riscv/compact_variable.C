/* { dg-do run } */
/* { dg-options "-O2" } */

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
