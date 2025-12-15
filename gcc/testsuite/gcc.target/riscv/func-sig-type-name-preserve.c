/* { dg-do compile } */
/* { dg-options "-O0 -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -fstrub=strict -fdump-ipa-strub" } */

/* Test that func_sig pass does not permanently modify TYPE_NAME.

   This is a regression test for a bug where the func_sig pass would
   modify TYPE_NAME (type) when converting IDENTIFIER_NODE to TYPE_DECL
   for mangling purposes. This permanent modification affected subsequent
   passes, particularly the strub pass.

   The bug was only visible when:
   1. Using C language (not C++)
   2. Using -mcf-branch-label-scheme=func-sig (default)
   3. Using -fstrub=strict
   4. Having struct parameters

   The strub pass would print "struct  param" instead of "struct MyStruct param"
   because TYPE_NAME had been modified by the func_sig pass.

   This test verifies that the type name is preserved correctly. */

struct MyStruct {
  int x;
  int y;
  int z;
  /* Make it large enough that the ABI will likely pass it via memory
     (indirectly), even though C still passes structs by value.  */
  int data[20];
};

/* This function will be processed by both func_sig and strub passes.
   The strub pass should see the original TYPE_NAME and print
   "struct MyStruct param" correctly. */
void __attribute__ ((__strub__))
test_func (struct MyStruct param)
{
  param.x = 1;
  param.y = 2;
  param.z = 3;
}

/* { dg-final { scan-ipa-dump "struct MyStruct param" "strub" } } */

