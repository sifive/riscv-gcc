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

/* Expected signature: FvP10foo_structE
   - F = Function
   - v = void return type
   - P = Pointer
   - 10foo_struct = struct name "foo_struct" (10 characters)
   - E = End of signature

   The typedef "foo" is canonicalized to the underlying struct name
   "foo_struct" by calling TYPE_MAIN_VARIANT in write_type(), matching
   the behavior of the C++ mangler (cp/mangle.cc). */
/* { dg-final { scan-assembler "lui\\tt2, %lpad_hash\\(\"FvP10foo_structE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\t%lpad_hash\\(\"FvP10foo_structE\"\\)" } } */
