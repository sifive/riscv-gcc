/* { dg-do compile } */
/* { dg-skip-if "Skipped due to codegen is changed by Combine pass" { riscv*-*-* } } */
/* { dg-options "-O2 -march=rv64gcb -mabi=lp64" } */

void setBit(char &a, int b) {
    char c = 0x1UL << b;
    a &= ~c;
    a ^= c;
}

/* { dg-final { scan-assembler-not "bclr\t" } } */
/* { dg-final { scan-assembler-not "xor\t" } } */
/* { dg-final { scan-assembler-not "andn\t" } } */
/* { dg-final { scan-assembler-times "bset\t" 1 } } */

