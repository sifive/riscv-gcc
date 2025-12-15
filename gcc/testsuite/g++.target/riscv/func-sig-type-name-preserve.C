/* { dg-do compile } */
/* { dg-options "-O0 -march=rv64gc_zicfilp_zicfiss -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -fstrub=strict -fdump-ipa-strub" } */

/* Test that func_sig pass works correctly with C++ (where TYPE_NAME is always TYPE_DECL).

   This is a companion test to the C version. In C++, TYPE_NAME is always TYPE_DECL,
   so the func_sig pass doesn't need to create a temporary TYPE_DECL. This test
   verifies that the C++ case still works correctly.

   This test also serves as a regression test to ensure that our fix for the C
   language case (using a local variable instead of modifying TYPE_NAME) doesn't
   break the C++ case. */

struct MyStruct {
  int x;
  int y;
  int z;
  int data[20];  /* Make it large enough to be passed by reference */
};

/* This function will be processed by both func_sig and strub passes.
   In C++, TYPE_NAME is already a TYPE_DECL, so no conversion is needed. */
void __attribute__ ((__strub__))
test_func (struct MyStruct param)
{
  param.x = 1;
  param.y = 2;
  param.z = 3;
}

/* { dg-final { scan-ipa-dump "struct MyStruct param" "strub" } } */

