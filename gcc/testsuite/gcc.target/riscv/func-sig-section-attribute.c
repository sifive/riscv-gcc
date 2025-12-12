/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

void my_init(void) {
}

__attribute__((section(".init_array")))
void (*my_init_ptr)(void) = my_init;

/* Test that functions referenced in .init_array get lpad 0.
   Functions in .init_array are declared with void(void) prototype but
   invoked using a generic function pointer void (*)(int, char**, char**).
   This leads to LPAD signature mismatches, so we use lpad 0 (unlabeled)
   for these functions to avoid CFI violations at runtime.  */
/* { dg-final { scan-assembler-times "lpad\[ \\t\]0" 1 } } */
