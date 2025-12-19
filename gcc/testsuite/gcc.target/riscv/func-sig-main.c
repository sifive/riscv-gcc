/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test that main function gets special signature FiiPPcE */

int main(int argc, char **argv)
{
  return 0;
}

/* Verify that main function uses the special fixed signature FiiPPcE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FiiPPcE\"\\)" } } */

