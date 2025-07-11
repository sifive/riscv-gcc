/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

void my_init(void) {
}

__attribute__((section(".init_array")))
void (*my_init_ptr)(void) = my_init;

/* { dg-final { scan-assembler-times "lpad\t0" 1 } } */
