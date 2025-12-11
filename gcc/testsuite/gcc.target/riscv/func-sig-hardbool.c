/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Test case for hardbool attribute handling in function signatures.
   This test verifies that the compiler doesn't crash when processing
   types with hardbool attribute.

   The fix:
   1. Replaces CP_DECL_CONTEXT with DECL_CONTEXT (C++ specific -> generic)
   2. Adds NULL checks in write_name and write_prefix
   3. Skips types with hardbool attribute in write_type

   hardbool is a C-only feature, so this test only works with gcc. */

typedef char __attribute__ ((hardbool (0, 1))) hbool;

hbool check_true(hbool x)
{
	return x;
}

hbool check_false(hbool x)
{
	return !x;
}

int use_hardbool(hbool a, hbool b)
{
	if (a && b)
		return 1;
	return 0;
}

int main()
{
	hbool t = 1;
	hbool f = 0;

	check_true(t);
	check_false(f);
	use_hardbool(t, f);

	return 0;
}

/* Verify that main function has the expected signature */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiiPPcE\"\\)" } } */

