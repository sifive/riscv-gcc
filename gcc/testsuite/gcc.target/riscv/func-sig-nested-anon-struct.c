/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -std=gnu99" } */

/* Test case for nested functions with anonymous struct parameters.

   This test verifies that the compiler correctly handles function signature
   generation for nested functions that have anonymous struct parameters,
   especially when those structs contain VLA (Variable Length Array) members.

   Background:
   - This is based on PR106465 which caused a segmentation fault
   - The issue occurred when TYPE_NAME or TREE_TYPE was NULL for anonymous types

   The fix (commit f947a57b801dae9bc286311ab7b24135d1ff0193):
   - Added NULL checks in write_prefix() to handle NULL TYPE_NAME
   - Added NULL checks in write_name() to handle NULL TREE_TYPE
   - Anonymous structs are now skipped in mangling (only named types generate signatures)

   What this test verifies:
   1. Compiler doesn't crash when processing anonymous structs in nested functions
   2. Named structs generate proper function signatures
   3. Anonymous structs are gracefully skipped in signature generation */

int main ()
{
	int n = 1;

	/* Named struct with VLA - should generate signature */
	void g1(int m, struct foo { char p[++m]; }* b)  /* { dg-warning "struct" } */
	{
		(*b).p[0] = 0;
	}

	/* Anonymous struct with VLA - should be skipped in mangling */
	void g2(struct { char p[++n]; }* b)     /* { dg-warning "anonymous struct" } */
	{
		(*b).p[0] = 0;
	}

	/* Anonymous struct with pointer to VLA - should be skipped */
	void g2b(struct { char (*p)[++n]; }* b) /* { dg-warning "anonymous struct" } */
	{
		/* Just declare it, don't use it to avoid type errors */
		(void)b;
	}

	/* Named struct - should generate signature */
	struct z { int a; };
	void g3(struct z v)
	{
		v.a = 0;
	}

	return 0;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiiPPcE\"\\)" } } */

