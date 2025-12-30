/* { dg-do compile } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -O2 -flto -fno-use-linker-plugin -flto-partition=none -fsanitize=object-size" } */

/* Test that function signature CFI works with sanitizer instrumentation.
   This used to cause an ICE when TYPE_MAIN_VARIANT returned the same type
   even with CV qualifiers present. */

struct S {
    int a;
    char b[10];
};

void foo(struct S *s, int n) {
    s->b[n] = 0;
}

int main() {
    struct S s;
    foo(&s, 0);
    return 0;
}

/* Check for correct function signatures:
   - foo: FvP1SiE (Function returning void, taking pointer to struct S and int)
   - main: FiiPPcE (Function returning int, taking int and char**)  */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\"FvP1SiE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\"FiiPPcE\"\\)" } } */

