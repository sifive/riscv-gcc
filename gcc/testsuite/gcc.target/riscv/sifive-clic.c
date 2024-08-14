/* { dg-do compile } */
/* { dg-options "-fomit-frame-pointer -march=rv64gc -mabi=lp64d" } */
/* { dg-skip-if "" { *-*-* } {"-O2" "-O3" "-Os" "-Og" "-Oz"} } */

static volatile int index = 0;

void __attribute__ ((interrupt("SiFive-CLIC-preemptible"))) vIsr_mtvt_beu ( void )
{
  index = 1;
}

int main() {
    vIsr_mtvt_beu();
    return 0;
}

/* { dg-final { scan-assembler "s\[wd\]\ts0,40" } } */
/* { dg-final { scan-assembler "s\[wd\]\ts1,32" } } */
/* { dg-final { scan-assembler "s\[wd\]\tt0,24" } } */
/* { dg-final { scan-assembler "l\[wd\]\tt0,24" } } */
/* { dg-final { scan-assembler "l\[wd\]\ts1,32" } } */
/* { dg-final { scan-assembler "l\[wd\]\ts0,40" } } */
