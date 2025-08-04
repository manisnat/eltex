#include <check.h>
#include "queue.h"
#include <stdlib.h>

START_TEST(test_init_queue) {
    PriorityQueue queue;
    Init(&queue);
    
    ck_assert_int_eq(queue.size, 0);
}
END_TEST

START_TEST(test_add_elements) {
    PriorityQueue queue;
    Init(&queue);
    
    AddElements(&queue, 100, 45);
    AddElements(&queue, 15, 234);
    AddElements(&queue, 25, 54);
    
    ck_assert_int_eq(queue.elements[0].data, 100);
    ck_assert_int_eq(queue.elements[0].priority, 45);
    ck_assert_int_eq(queue.elements[1].data, 15);
    ck_assert_int_eq(queue.elements[1].priority, 234);
    ck_assert_int_eq(queue.elements[2].data, 25);
    ck_assert_int_eq(queue.elements[2].priority, 54);
    ck_assert_int_eq(queue.size, 3);
    
}
END_TEST

START_TEST(test_extract_first_elment) {
    PriorityQueue queue;
    Init(&queue);
    
    AddElements(&queue, 100, 45);
    AddElements(&queue, 15, 234);
    AddElements(&queue, 25, 54);

    int data;
    ExtractFirstElement(&queue, &data);
    
    ck_assert_int_eq(data, 100);
    ck_assert_int_eq(queue.elements[0].data, 15);
    ck_assert_int_eq(queue.elements[0].priority, 234);
    ck_assert_int_eq(queue.elements[1].data, 25);
    ck_assert_int_eq(queue.elements[1].priority, 54);
    ck_assert_int_eq(queue.size, 2);
    
}
END_TEST

START_TEST(test_extract_elment_priority) {
    PriorityQueue queue;
    Init(&queue);
    
    AddElements(&queue, 100, 45);
    AddElements(&queue, 15, 234);
    AddElements(&queue, 25, 54);

    int data = 0, priority = 234;
    ExtractElementPriority(&queue, priority, &data);
    
    ck_assert_int_eq(data, 15);
    ck_assert_int_eq(queue.elements[0].data, 100);
    ck_assert_int_eq(queue.elements[0].priority, 45);
    ck_assert_int_eq(queue.elements[1].data, 25);
    ck_assert_int_eq(queue.elements[1].priority, 54);
    ck_assert_int_eq(queue.size, 2);
    
}
END_TEST

START_TEST(test_extract_elment_higher_priority) {
    PriorityQueue queue;
    Init(&queue);
    
    AddElements(&queue, 100, 45);
    AddElements(&queue, 15, 234);
    AddElements(&queue, 25, 54);

    int data = 0, priority = 200;
    ExtractElementHigherPriority(&queue, priority, &data);
    
    ck_assert_int_eq(data, 15);
    ck_assert_int_eq(queue.elements[0].data, 100);
    ck_assert_int_eq(queue.elements[0].priority, 45);
    ck_assert_int_eq(queue.elements[1].data, 25);
    ck_assert_int_eq(queue.elements[1].priority, 54);
    ck_assert_int_eq(queue.size, 2);
    
}
END_TEST

Suite* phone_book_suite(void) {
    Suite* s = suite_create("Phone Book");
    
    TCase* tc_core = tcase_create("Core Functions");
    tcase_add_test(tc_core, test_init_queue);
    tcase_add_test(tc_core, test_add_elements);
    tcase_add_test(tc_core, test_extract_first_elment);
    tcase_add_test(tc_core, test_extract_elment_priority);
    tcase_add_test(tc_core, test_extract_elment_higher_priority);

    suite_add_tcase(s, tc_core);
    
    return s;
}

int main(void) {
    int number_failed;
    Suite* s = phone_book_suite();
    SRunner* sr = srunner_create(s);
    
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}