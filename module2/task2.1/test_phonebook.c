#include <check.h>
#include <stdlib.h>
#include "phone_book.h"

#define TEST_CAPACITY 5

START_TEST(test_init_book) {
    PhoneBook book;
    int result = InitBook(&book, TEST_CAPACITY);
    
    ck_assert_int_eq(result, 0);
    ck_assert_ptr_nonnull(book.data);
    ck_assert_int_eq(book.size, 0);
    ck_assert_int_eq(book.capacity, TEST_CAPACITY);
    
    free(book.data);
}
END_TEST

START_TEST(test_add_contact) {
    PhoneBook book;
    InitBook(&book, TEST_CAPACITY);
    
    Person p = {
        .firstName = "John",
        .lastName = "Doe",
        .PlaceWork = "Company",
        .jobTitle = "Developer",
        .workPhone = "1234567",
        .personalPhone = "7654321"
    };
    
    int result = AddContact(&book, &p);
    
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(book.size, 1);
    ck_assert_str_eq(book.data[0].firstName, "John");
    ck_assert_str_eq(book.data[0].lastName, "Doe");
    
    free(book.data);
}
END_TEST

START_TEST(test_add_contact_full) {
    PhoneBook book;
    InitBook(&book, 1); // Емкость только для одного контакта
    
    Person p1 = {"John", "Doe"};
    Person p2 = {"Jane", "Smith"};
    
    AddContact(&book, &p1);
    int result = AddContact(&book, &p2); // Попытка добавить второй контакт
    
    ck_assert_int_eq(result, 1);
    ck_assert_int_eq(book.size, 1); // Размер не должен измениться
    
    free(book.data);
}
END_TEST

START_TEST(test_edit_contact) {
    PhoneBook book;
    InitBook(&book, TEST_CAPACITY);
    
    Person p = {"John", "Doe"};
    AddContact(&book, &p);
    
    Person new_data = {.firstName = "Johnny", .lastName = ""}; // Меняем только имя
    EditContact(&book, &new_data, 0);
    
    ck_assert_str_eq(book.data[0].firstName, "Johnny");
    ck_assert_str_eq(book.data[0].lastName, "Doe"); // Фамилия не изменилась
    
    free(book.data);
}
END_TEST

START_TEST(test_edit_contact_invalid_id) {
    PhoneBook book;
    InitBook(&book, TEST_CAPACITY);
    
    Person p1 = {"John", "Doe"};
    AddContact(&book, &p1);

    Person p2 = {"", "Do"};
    
    int result = EditContact(&book, &p2, 1); // Неверный ID
    
    ck_assert_int_eq(result, -1);
    
    free(book.data);
}
END_TEST

START_TEST(test_delete_contact) {
    PhoneBook book;
    InitBook(&book, TEST_CAPACITY);
    
    Person p1 = {"John", "Doe"};
    Person p2 = {"Jane", "Smith"};
    AddContact(&book, &p1);
    AddContact(&book, &p2);
    
    int result = DeleteContact(&book, 0);
    
    ck_assert_int_eq(result, 0);
    ck_assert_int_eq(book.size, 1);
    ck_assert_str_eq(book.data[0].firstName, "Jane");
    
    free(book.data);
}
END_TEST

START_TEST(test_delete_contact_invalid_id) {
    PhoneBook book;
    InitBook(&book, TEST_CAPACITY);
    
    int result = DeleteContact(&book, 0); // Пустая книга
    
    ck_assert_int_eq(result, 1);
    
    Person p = {"John", "Doe"};
    AddContact(&book, &p);
    
    result = DeleteContact(&book, 1); // Неверный ID
    
    ck_assert_int_eq(result, -1);
    ck_assert_int_eq(book.size, 1);
    
    free(book.data);
}
END_TEST

Suite* phone_book_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("PhoneBook");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_init_book);
    tcase_add_test(tc_core, test_add_contact);
    tcase_add_test(tc_core, test_add_contact_full);
    tcase_add_test(tc_core, test_edit_contact);
    tcase_add_test(tc_core, test_edit_contact_invalid_id);
    tcase_add_test(tc_core, test_delete_contact);
    tcase_add_test(tc_core, test_delete_contact_invalid_id);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = phone_book_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}