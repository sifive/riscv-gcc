/* Verify the no_cfi_lp attribute with function pointer.  */
/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d" } */

typedef void (*func_ptr)();

__attribute__((no_cfi_lp))
void bar(func_ptr ptr){
 ptr(); // No need to setup t2 before function call.
}

/* { dg-final { scan-assembler-not "lpad\t" } } */
/* { dg-final { scan-assembler-not "lui\tt2,1" } } */
