/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O0" } */

/* Test function signature generation for pointer types */

int* get_pointer(int *p)
{
  return p;
}

void process_array(int *arr, int size)
{
}

char* string_copy(const char *src, char *dst)
{
  return dst;
}

void** get_void_ptr(void)
{
  return 0;
}

/* Verify function signatures:
   get_pointer: int*(int*) -> FPiS_E (S_ = substitution for int*)
   process_array: void(int*, int) -> FvPiiE
   string_copy: char*(const char*, char*) -> FPcPKcS_E (K=const, S_=subst)
   get_void_ptr: void**(void) -> FPPvvE */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FPiS_E\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FvPiiE\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FPcPKcS_E\"\\)" } } */
/* { dg-final { scan-assembler "%lpad_hash\\(\"FPPvvE\"\\)" } } */

