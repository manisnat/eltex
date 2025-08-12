#include <check.h>  
#include <dlfcn.h>  
#include <stdlib.h>

typedef int (*operation_func)(double*, int, ...);

START_TEST(test_add) {
    double result = 0.0;
    void* handle;
    operation_func func; 

    handle = dlopen("./libs/libadd.so", RTLD_LAZY);
    ck_assert_ptr_nonnull(handle);

    func = (operation_func)dlsym(handle, "add");
    ck_assert_ptr_nonnull(func);
    
    ck_assert_int_eq(func(&result, 2, 5.0, 3.0), 0);
    ck_assert_double_eq_tol(result, 8.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 5, 1.0, 2.0, 3.0, 4.0, 5.0), 0);
    ck_assert_double_eq_tol(result, 15.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 3, -5.0, 10.0, -3.0), 0);
    ck_assert_double_eq_tol(result, 2.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 0), 1);

    dlclose(handle);
}
END_TEST

START_TEST(test_sub) {
    double result = 0.0;
    void* handle;
    operation_func func; 

    handle = dlopen("./libs/libsub.so", RTLD_LAZY);
    ck_assert_ptr_nonnull(handle);

    func = (operation_func)dlsym(handle, "sub");
    ck_assert_ptr_nonnull(func);
    
    ck_assert_int_eq(func(&result, 2, 10.0, 3.0), 0);
    ck_assert_double_eq_tol(result, 7.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 4, 20.0, 5.0, 3.0, 2.0), 0);
    ck_assert_double_eq_tol(result, 10.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 3, -5.0, -10.0, -3.0), 0);
    ck_assert_double_eq_tol(result, 8.0, 1e-6);

    dlclose(handle);
}
END_TEST

START_TEST(test_mult) {
    double result = 0.0;
    void* handle;
    operation_func func; 

    handle = dlopen("./libs/libmult.so", RTLD_LAZY);
    ck_assert_ptr_nonnull(handle);

    func = (operation_func)dlsym(handle, "mult");
    ck_assert_ptr_nonnull(func);
    
    ck_assert_int_eq(func(&result, 2, 5.0, 3.0), 0);
    ck_assert_double_eq_tol(result, 15.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 4, 1.0, 2.0, 3.0, 4.0), 0);
    ck_assert_double_eq_tol(result, 24.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 3, -2.0, 3.0, -4.0), 0);
    ck_assert_double_eq_tol(result, 24.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 3, 5.0, 0.0, 3.0), 0);
    ck_assert_double_eq_tol(result, 0.0, 1e-6);

    dlclose(handle);
}
END_TEST

START_TEST(test_div) {
    double result = 0.0;
    void* handle;
    operation_func func; 

    handle = dlopen("./libs/libdivide.so", RTLD_LAZY);
    ck_assert_ptr_nonnull(handle);

    func = (operation_func)dlsym(handle, "divide");
    ck_assert_ptr_nonnull(func);
    
    ck_assert_int_eq(func(&result, 2, 10.0, 2.0), 0);
    ck_assert_double_eq_tol(result, 5.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 3, 100.0, 5.0, 2.0), 0);
    ck_assert_double_eq_tol(result, 10.0, 1e-6);
    
    ck_assert_int_eq(func(&result, 2, 10.0, 0.0), -1);
    
    ck_assert_int_eq(func(&result, 3, -100.0, 5.0, -2.0), 0);
    ck_assert_double_eq_tol(result, 10.0, 1e-6);

    dlclose(handle);
}
END_TEST

Suite *calculator_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculator");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add);
    tcase_add_test(tc_core, test_sub);
    tcase_add_test(tc_core, test_mult);
    tcase_add_test(tc_core, test_div);
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}