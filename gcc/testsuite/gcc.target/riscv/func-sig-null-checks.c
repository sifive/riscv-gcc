/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Test case for NULL pointer checks in function signature mangling.

   This test verifies that the compiler properly handles edge cases
   where TYPE_NAME, TREE_TYPE, or DECL_CONTEXT may be NULL.

   The fixes in commit f947a57b801dae9bc286311ab7b24135d1ff0193:

   1. In decl_mangling_context():
      - Replace CP_DECL_CONTEXT (C++ specific) with DECL_CONTEXT (generic)
      - This allows the code to work in both C and C++

   2. In write_name():
      - Add NULL check for decl parameter
      - Add NULL check after TYPE_NAME(context) in the context traversal loop

   3. In write_prefix():
      - Add NULL check for decl after TYPE_NAME(node)
      - Add NULL check for TREE_TYPE(decl)

   4. In write_type():
      - Skip types with hardbool attribute (C-only feature)

   These checks prevent segmentation faults when processing:
   - Anonymous structs/unions
   - Types with special attributes (hardbool)
   - Nested functions with complex parameter types
*/

/* Test 1: Anonymous struct (TYPE_NAME is NULL) */
void test_anon_struct(struct { int x; } *p) /* { dg-warning "anonymous struct" } */
{
	if (p)
		p->x = 0;
}

/* Test 2: Named struct (normal case) */
struct NamedStruct { int y; };
void test_named_struct(struct NamedStruct *p)
{
	p->y = 0;
}

/* Test 3: Typedef to anonymous struct */
typedef struct { int z; } TypedefStruct;
void test_typedef_struct(TypedefStruct *p)
{
	p->z = 0;
}

/* Test 4: Nested anonymous struct */
struct Outer {
	struct { int inner; } anon;
};
void test_nested_anon(struct Outer *p)
{
	p->anon.inner = 0;
}

int main()
{
	return 0;
}

/* Verify that main function has the expected signature */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiiPPcE\"\\)" } } */

