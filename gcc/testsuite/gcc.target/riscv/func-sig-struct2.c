/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

struct linux_binprm {
 char buf[256];
} __attribute__((__designated_init__));

int cap_bprm_creds_from_file(struct linux_binprm *bprm)
{
 return 0;
}

/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FiP12linux_binprmE\"\\)" } } */
