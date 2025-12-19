/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-O0 -march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig" } */

struct foo_struct;
typedef struct foo_struct foo;

typedef void (*callback_t)(foo *);

void callsite(callback_t cb, foo *p) {
  cb(p);
}

struct foo_struct { int x; };

static void real_cb(struct foo_struct *p) {
  p->x = 123;
}

void test() {
  callsite(real_cb, 0);
}

/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FvP10foo_structE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FvP10foo_structE\"\\)" } } */
