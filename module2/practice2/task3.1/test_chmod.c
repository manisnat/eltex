#include <check.h>
#include <stdlib.h>
#include "chmod.h"

START_TEST(test_valid_letters) {
    ck_assert_int_eq(valid_letters("rwxrwxrwx"), 0);
    ck_assert_int_eq(valid_letters("r-xr-xr-x"), 0);
    ck_assert_int_eq(valid_letters("---------"), 0);
    
    ck_assert_int_eq(valid_letters(""), 1);
    ck_assert_int_eq(valid_letters("rwxrwxrw"), 1);
    ck_assert_int_eq(valid_letters("rwxrwxrwxx"), 1);
    ck_assert_int_eq(valid_letters("rwxrwxrw!"), 1);
    ck_assert_int_eq(valid_letters("rwxrwxrww"), 1);
}
END_TEST

START_TEST(test_letters_in_octal) {
    ck_assert_int_eq(letters_in_octal("rwxrwxrwx"), 0777);
    ck_assert_int_eq(letters_in_octal("r-xr-xr-x"), 0555);
    ck_assert_int_eq(letters_in_octal("r--r--r--"), 0444);
    ck_assert_int_eq(letters_in_octal("---------"), 0);
    ck_assert_int_eq(letters_in_octal("rwx------"), 0700);
    ck_assert_int_eq(letters_in_octal("---rwx---"), 0070);
    ck_assert_int_eq(letters_in_octal("------rwx"), 0007);
    
    ck_assert_int_eq(letters_in_octal("invalid"), -1);
}
END_TEST

START_TEST(test_octal_in_letters) {
    char letters[10];
    
    ck_assert_int_eq(octal_in_letters(0777, letters), 0);
    ck_assert_str_eq(letters, "rwxrwxrwx");
    
    ck_assert_int_eq(octal_in_letters(0755, letters), 0);
    ck_assert_str_eq(letters, "rwxr-xr-x");
    
    ck_assert_int_eq(octal_in_letters(0644, letters), 0);
    ck_assert_str_eq(letters, "rw-r--r--");
    
    ck_assert_int_eq(octal_in_letters(0, letters), 0);
    ck_assert_str_eq(letters, "---------");
    
    ck_assert_int_eq(octal_in_letters(-1, letters), 1);
    ck_assert_int_eq(octal_in_letters(01000, letters), 1);
}
END_TEST

START_TEST(test_edit_right) {
    int octal;
    
    octal = 0;
    ck_assert_int_eq(edit_right("u+rw", &octal), 0);
    ck_assert_int_eq(octal, 0600);
    
    octal = 0777;
    ck_assert_int_eq(edit_right("go-w", &octal), 0);
    ck_assert_int_eq(octal, 0755);
    
    octal = 0644;
    ck_assert_int_eq(edit_right("a+x", &octal), 0);
    ck_assert_int_eq(octal, 0755);
    
    octal = 0755;
    ck_assert_int_eq(edit_right("u=rw", &octal), 0);
    ck_assert_int_eq(octal, 0655);

    octal = 0755;
    ck_assert_int_eq(edit_right("-x", &octal), 0);
    ck_assert_int_eq(octal, 0644);

    
    octal = 0;
    ck_assert_int_eq(edit_right("invalid", &octal), 1);
    ck_assert_int_eq(edit_right("a+", &octal), 1);
    ck_assert_int_eq(edit_right("u+r+w", &octal), 1);
}
END_TEST

START_TEST(test_stat_file) {
    int octal;
    FILE *tmp = fopen("testfile.tmp", "w");
    fclose(tmp);
    
    chmod("testfile.tmp", 0644);
    ck_assert_int_eq(stat_file("testfile.tmp", &octal), 0);
    ck_assert_int_eq(octal, 0644);
    
    ck_assert_int_eq(stat_file("nonexistent", &octal), 1);
    
    remove("testfile.tmp");
}
END_TEST

Suite *chmod_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Chmod");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_valid_letters);
    tcase_add_test(tc_core, test_letters_in_octal);
    tcase_add_test(tc_core, test_octal_in_letters);
    tcase_add_test(tc_core, test_edit_right);
    tcase_add_test(tc_core, test_stat_file);
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = chmod_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}