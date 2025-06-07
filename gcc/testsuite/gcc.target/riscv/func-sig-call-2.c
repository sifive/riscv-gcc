/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

/* Verify the function signature with function pointer from typedef.  */

typedef void (*func_ptr)();

void bar (func_ptr ptr){
 ptr();
}

/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FvvE\"\\)" } } */
