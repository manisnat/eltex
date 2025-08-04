#include <check.h>
#include "phone_book.h"
#include <stdlib.h>

START_TEST(test_init_list) {
    Snake list;
    Init(&list);
    
    ck_assert_ptr_null(list.head);
    ck_assert_ptr_null(list.tail);
}
END_TEST

START_TEST(test_add_single_contact) {
    Snake list;
    Init(&list);
    
    Person p = {"Smith", "John", "Company", "Developer", "123", "456", 
                "john@mail", "@john", "vk.com/john"};
    
    Item* added = AddContact(&p, &list);
    
    ck_assert_ptr_nonnull(added);
    ck_assert_ptr_eq(list.head, added);
    ck_assert_ptr_eq(list.tail, added);
    ck_assert_str_eq(added->data->lastName, "Smith");
    ck_assert_str_eq(added->data->firstName, "John");
    
    DeleteList(&list);
}
END_TEST

START_TEST(test_contact_ordering) {
    Snake list;
    Init(&list);
    
    Person p1 = {"Smith", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Adams", "Alice", "", "", "", "", "", "", ""};
    Person p3 = {"Smith", "Anna", "", "", "", "", "", "", ""};
    
    AddContact(&p1, &list);
    AddContact(&p2, &list);
    AddContact(&p3, &list);
    
    ck_assert_str_eq(list.head->data->lastName, "Adams");
    ck_assert_str_eq(list.head->next->data->lastName, "Smith");
    ck_assert_str_eq(list.head->next->data->firstName, "Anna");
    ck_assert_str_eq(list.tail->data->lastName, "Smith");
    ck_assert_str_eq(list.tail->data->firstName, "John");
    
    DeleteList(&list);
}
END_TEST

START_TEST(test_delete_contact) {
    Snake list;
    Init(&list);
    
    Person p1 = {"Smith", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Adams", "Alice", "", "", "", "", "", "", ""};
    
    AddContact(&p1, &list);
    AddContact(&p2, &list);
    
    int res = DeleteContact(&list, "Adams", "Alice");
    ck_assert_int_eq(res, 0);
    ck_assert_ptr_eq(list.head, list.tail);
    ck_assert_str_eq(list.head->data->lastName, "Smith");
    
    res = DeleteContact(&list, "NonExistent", "Name");
    ck_assert_int_eq(res, -1);
    
    DeleteList(&list);
}
END_TEST

START_TEST(test_edit_contact) {
    Snake list;
    Init(&list);
    
    Person p = {"Smith", "John", "OldComp", "Dev", "123", "456", "", "", ""};
    AddContact(&p, &list);
    
    Person changes = {"", "", "NewComp", "", "", "", "", "", ""};
    int res = EditContact(&list, &changes, "Smith", "John");
    
    ck_assert_int_eq(res, 0);
    ck_assert_str_eq(list.head->data->PlaceWork, "NewComp");
    ck_assert_str_eq(list.head->data->lastName, "Smith");
    
    // Тест изменения имени с перестановкой
    Person name_change = {"Taylor", "", "", "", "", "", "", "", ""};
    res = EditContact(&list, &name_change, "Smith", "John");
    
    ck_assert_int_eq(res, 0);
    ck_assert_str_eq(list.head->data->lastName, "Taylor");
    
    DeleteList(&list);
}
END_TEST

START_TEST(test_delete_list) {
    Snake list;
    Init(&list);
    
    Person p1 = {"Smith", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Adams", "Alice", "", "", "", "", "", "", ""};
    
    AddContact(&p1, &list);
    AddContact(&p2, &list);
    
    DeleteList(&list);
    
    ck_assert_ptr_null(list.head);
    ck_assert_ptr_null(list.tail);
}
END_TEST

START_TEST(test_find_nonexistent) {
    Snake list;
    Init(&list);
    
    Person p = {"Smith", "John", "", "", "", "", "", "", ""};
    AddContact(&p, &list);
    
    int res = DeleteContact(&list, "Nonexistent", "Name");
    ck_assert_int_eq(res, -1);
    
    Person changes = {"", "", "", "", "", "", "", "", ""};
    res = EditContact(&list, &changes, "Nonexistent", "Name");
    ck_assert_int_eq(res, -1);
    
    DeleteList(&list);
}
END_TEST

START_TEST(test_add_empty_fields) {
    Snake list;
    Init(&list);
    
    Person p = {"", "", "", "", "", "", "", "", ""};
    Item* added = AddContact(&p, &list);
    
    ck_assert_ptr_nonnull(added);
    ck_assert_str_eq(added->data->lastName, "");
    ck_assert_str_eq(added->data->firstName, "");
    
    DeleteList(&list);
}
END_TEST

Suite* phone_book_suite(void) {
    Suite* s = suite_create("Phone Book");
    
    TCase* tc_core = tcase_create("Core Functions");
    tcase_add_test(tc_core, test_init_list);
    tcase_add_test(tc_core, test_add_single_contact);
    tcase_add_test(tc_core, test_contact_ordering);
    tcase_add_test(tc_core, test_delete_contact);
    tcase_add_test(tc_core, test_edit_contact);
    tcase_add_test(tc_core, test_delete_list);
    tcase_add_test(tc_core, test_find_nonexistent);
    tcase_add_test(tc_core, test_add_empty_fields);
    
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