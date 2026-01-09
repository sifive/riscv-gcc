/* { dg-do compile { target { riscv64*-*-* } } } */
/* { dg-options "-march=rv64gc_zicfiss_zicfilp -mabi=lp64d -fcf-protection=full -mcf-branch-label-scheme=func-sig -O2" } */

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
__attribute__((noinline))
int test_pointer_to_data_member(T& obj, int T::*pdm)
{
    return obj.*pdm;
}

/* Test 2: Pointer-to-member-function (RECORD_TYPE with TYPE_LANG_FLAG_2) */
__attribute__((noinline))
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
__attribute__((noinline))
int test_template_invoke()
{
    T obj;
    obj.value = 42;

    int (T::*pmf)() = &T::get_value;
    return invoke_impl<int>(pmf, obj);
}

/* Test 5: Reference to pointer-to-member */
__attribute__((noinline))
int test_reference_to_pointer_to_member(T& obj, int (T::*& pmf)())
{
    return (obj.*pmf)();
}

/* Test 6: Pointer to pointer-to-member */
__attribute__((noinline))
int test_pointer_to_pointer_to_member(T& obj, int (T::**ppmf)())
{
    return (obj.**ppmf)();
}

/* Test 7: Array of pointer-to-member */
typedef int (T::*MemberFuncPtr)();
__attribute__((noinline))
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

__attribute__((noinline))
int test_nested_template()
{
    T obj;
    obj.value = 100;
    return Invoker<T, int, int (T::*)()>::call(obj, &T::get_value);
}

/* Test 9: Multiple pointer-to-member parameters */
__attribute__((noinline))
void test_multiple_pointer_to_member(T& obj,
                                      int T::*pdm1,
                                      int T::*pdm2,
                                      int (T::*pmf)())
{
    obj.*pdm1 = obj.*pdm2;
    (obj.*pmf)();
}

/* Test 10: Const pointer-to-member */
__attribute__((noinline))
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

/* Check for pointer-to-member-function type: M<class><return><function>E
   Example: M1TFivE = pointer to member function of class T returning int */
/* { dg-final { scan-assembler "lpad.*M1.*Fiv" } } */

/* Check for function taking pointer-to-data-member: FiR1TMS_iE
   R1T = reference to class T
   MS_i = pointer-to-data-member of type int */
/* { dg-final { scan-assembler "lpad.*MS_" } } */

/* Check for function taking pointer-to-member-function: FiR1TMS_FivEE
   MS_FivE = pointer-to-member-function returning int with void params */
/* { dg-final { scan-assembler "lpad.*MS_Fiv" } } */

/* Check for reference to pointer-to-member: TRMS_
   R = reference, M = pointer-to-member */
/* { dg-final { scan-assembler "lpad.*TRMS_" } } */

/* Check for pointer to pointer-to-member: TPMS_
   P = pointer, M = pointer-to-member */
/* { dg-final { scan-assembler "lpad.*TPMS_" } } */

/* Check for const pointer-to-member: RK1TMS_KFivE
   RK1T = reference to const class T
   MS_KFivE = pointer-to-member-function that is const */
/* { dg-final { scan-assembler "lpad.*RK1TMS_KFiv" } } */

/* Check for main function */
/* { dg-final { scan-assembler "lpad.*FiiPPcE" } } */

