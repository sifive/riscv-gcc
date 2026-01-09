/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O2" } */

/* Test that function signature CFI doesn't cause ICE with typedef and enum.
   
   This used to cause:
     internal compiler error: same canonical type node for different types
     'wint_t' {aka 'unsigned int'} and 'enum category'
   
   The bug was caused by calling TYPE_MAIN_VARIANT twice in write_type(),
   which corrupted the type system's canonical type nodes.
   
   Based on newlib's categories.c which triggered the original bug. */

typedef unsigned int wint_t;

enum category {
  CAT_A,
  CAT_B,
  CAT_C
};

/* Function using both typedef and enum in signature.
   This combination used to trigger the canonical type node corruption. */
enum category get_category(wint_t value)
{
  if (value < 100)
    return CAT_A;
  else if (value < 200)
    return CAT_B;
  else
    return CAT_C;
}

/* Another function to ensure both types are processed */
wint_t get_value(enum category cat)
{
  switch (cat)
    {
    case CAT_A: return 50;
    case CAT_B: return 150;
    case CAT_C: return 250;
    default: return 0;
    }
}

int main()
{
  wint_t val = 123;
  enum category cat = get_category(val);
  wint_t result = get_value(cat);
  return result;
}

/* Check that function signatures are generated correctly:
   - get_category: F8categoryjE (returns enum category, takes wint_t/unsigned int)
   - get_value: Fj8categoryE (returns wint_t/unsigned int, takes enum category)
   - main: FiiPPcE (standard main signature)

   Note: '8category' represents enum category (8 chars in name)
         'j' represents unsigned int (wint_t's underlying type)

   Important: enum category and wint_t (unsigned int) should NOT share
   substitutions because they are different types (ENUMERAL_TYPE vs INTEGER_TYPE).
   The fix ensures TREE_CODE is checked before same_type_p() in find_substitution(). */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\"F8categoryjE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\"Fj8categoryE\"\\)" } } */
/* { dg-final { scan-assembler "lpad\\s+%lpad_hash\\(\"FiiPPcE\"\\)" } } */

