/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-march=rv64gc_zicfilp -mabi=lp64d -fcf-protection=branch -mcf-branch-label-scheme=func-sig -O2" } */

/* Test that CFI works correctly with pointer-to-member types.

   This used to cause:
     internal compiler error: Segmentation fault
     in write_pointer_to_member_type, at cp/mangle.cc:4276

   The bug was caused by TYPE_PTRMEM_CLASS_TYPE returning NULL after
   LTO serialization/deserialization, leading to a segfault when the
   C++ mangler tried to mangle pointer-to-member types.

   The fix splits the func_sig pass into early and late passes:
   - Early pass runs before pass_ipa_free_lang_data, when type info is valid
   - Late pass runs after SSA construction, for analyzing indirect calls

   This allows us to handle pointer-to-member types correctly even with LTO,
   providing full CFI protection for ALL functions.

   Based on the reproducer from t_mem_fn_id63.ii which triggered the bug. */

struct T {
    int value;
    
    int get_value() { return value; }
    void set_value(int v) { value = v; }
};

/* Test 1: Pointer-to-data-member (OFFSET_TYPE) */
int test_pointer_to_data_member(T& obj, int T::*pdm)
{
    return obj.*pdm;
}

/* Test 2: Pointer-to-member-function (RECORD_TYPE with TYPE_LANG_FLAG_2) */
int test_pointer_to_member_function(T& obj, int (T::*pmf)())
{
    return (obj.*pmf)();
}

/* Test 3: Template function with pointer-to-member parameter
   This is the main case that used to cause ICE */
template<typename R, typename Fn, typename Tp>
R invoke_impl(Fn&& f, Tp&& t)
{
    return (t.*f)();
}

/* Test 4: Using the template with pointer-to-member-function */
int test_template_invoke()
{
    T obj;
    obj.value = 42;
    
    int (T::*pmf)() = &T::get_value;
    return invoke_impl<int>(pmf, obj);
}

/* Test 5: Reference to pointer-to-member */
int test_reference_to_pointer_to_member(T& obj, int (T::*& pmf)())
{
    return (obj.*pmf)();
}

/* Test 6: Pointer to pointer-to-member */
int test_pointer_to_pointer_to_member(T& obj, int (T::**ppmf)())
{
    return (obj.**ppmf)();
}

/* Test 7: Array of pointer-to-member */
typedef int (T::*MemberFuncPtr)();
int test_array_of_pointer_to_member(T& obj, MemberFuncPtr funcs[], int index)
{
    return (obj.*(funcs[index]))();
}

/* Test 8: Nested template with pointer-to-member */
template<typename T, typename R, typename Fn>
struct Invoker {
    static R call(T& obj, Fn f) {
        return (obj.*f)();
    }
};

int test_nested_template()
{
    T obj;
    obj.value = 100;
    return Invoker<T, int, int (T::*)()>::call(obj, &T::get_value);
}

/* Test 9: Multiple pointer-to-member parameters */
void test_multiple_pointer_to_member(T& obj, 
                                      int T::*pdm1, 
                                      int T::*pdm2,
                                      int (T::*pmf)())
{
    obj.*pdm1 = obj.*pdm2;
    (obj.*pmf)();
}

/* Test 10: Const pointer-to-member */
int test_const_pointer_to_member(const T& obj, int (T::*pmf)() const)
{
    return (obj.*pmf)();
}

int main()
{
    T obj;
    obj.value = 42;
    
    // Test pointer-to-data-member
    int T::*pdm = &T::value;
    int result1 = test_pointer_to_data_member(obj, pdm);
    
    // Test pointer-to-member-function
    int (T::*pmf)() = &T::get_value;
    int result2 = test_pointer_to_member_function(obj, pmf);
    
    // Test template invoke
    int result3 = test_template_invoke();
    
    // Test reference to pointer-to-member
    int result4 = test_reference_to_pointer_to_member(obj, pmf);
    
    // Test nested template
    int result5 = test_nested_template();
    
    return result1 + result2 + result3 + result4 + result5;
}

/* The test should compile without ICE.

   With the early/late pass split, ALL functions now get lpad_func_sig
   attributes, including those with pointer-to-member types. The early
   pass runs before type information is lost, so it can correctly mangle
   pointer-to-member types even with LTO.

   We should see lpad instructions for all functions, including:
   - test_pointer_to_member_function (has pointer-to-member parameter)
   - invoke_impl (template with pointer-to-member parameter)
   - main (regular function)

   This provides full CFI protection without compiler crashes. */

/* { dg-final { scan-assembler "lpad" } } */

