#include "phone_book.h"
#include <check.h>
#include <stdlib.h>

START_TEST(test_create_node) {
    Person p = {"Doe", "John", "Company", "Manager", "123", "456", "a@b.c", "@tg", "@vk"};
    TreeNode* node = createNode(&p);
    
    ck_assert_ptr_nonnull(node);
    ck_assert_ptr_nonnull(node->data);
    ck_assert_str_eq(node->data->lastName, "Doe");
    ck_assert_str_eq(node->data->firstName, "John");
    ck_assert_ptr_null(node->left);
    ck_assert_ptr_null(node->right);
    
    free(node->data);
    free(node);
}
END_TEST

START_TEST(test_add_contact) {
    TreeNode* root = NULL;
    Person p1 = {"Doe", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Smith", "Alice", "", "", "", "", "", "", ""};
    Person p3 = {"Anderson", "Bob", "", "", "", "", "", "", ""};
    
    root = AddContact(&p1, root);
    root = AddContact(&p2, root);
    root = AddContact(&p3, root);
    
    ck_assert_ptr_nonnull(root);
    ck_assert_ptr_nonnull(root->left);  
    ck_assert_ptr_nonnull(root->right); 
    
    DeleteTree(root);
}
END_TEST

START_TEST(test_print_empty_tree) {
    TreeNode* root = NULL;
    int counter = 1;
    
    int result = PrintContacts(root, &counter);
    ck_assert_int_eq(result, 1);
    
    result = PrettyPrintTree(root, 0, 0);
    ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_delete_contact) {
    TreeNode* root = NULL;
    Person p1 = {"Doe", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Smith", "Alice", "", "", "", "", "", "", ""};
    
    root = AddContact(&p1, root);
    root = AddContact(&p2, root);
    
    int found = 0;
    root = DeleteContact(root, "Doe", "John", &found);
    ck_assert_int_eq(found, 1);
    ck_assert_str_eq(root->data->lastName, "Smith");
    
    found = 0;
    root = DeleteContact(root, "Nonexistent", "Person", &found);
    ck_assert_int_eq(found, 0);
    
    DeleteTree(root);
}
END_TEST

START_TEST(test_edit_contact) {
    TreeNode* root = NULL;
    Person p1 = {"Doe", "John", "Old", "", "", "", "", "", ""};
    Person p2 = {"Smith", "Alice", "", "", "", "", "", "", ""};
    Person new_data = {"Doe", "John", "New", "", "", "", "", "", ""};
    
    root = AddContact(&p1, root);
    root = AddContact(&p2, root);
    
    int found = 0;
    root = EditContact(root, &new_data, "Doe", "John", &found);
    ck_assert_int_eq(found, 1);
    
    TreeNode* current = root;
    while (current != NULL) {
        int cmp = strcmp("Doe", current->data->lastName);
        if (cmp == 0) {
            cmp = strcmp("John", current->data->firstName);
            if (cmp == 0) break;
        }
        current = cmp < 0 ? current->left : current->right;
    }
    
    ck_assert_ptr_nonnull(current);
    ck_assert_str_eq(current->data->PlaceWork, "New");
    
    DeleteTree(root);
}
END_TEST

START_TEST(test_find_min) {
    TreeNode* root = NULL;
    Person p1 = {"Doe", "John", "", "", "", "", "", "", ""};
    Person p2 = {"Smith", "Alice", "", "", "", "", "", "", ""};
    Person p3 = {"Anderson", "Bob", "", "", "", "", "", "", ""};
    
    root = AddContact(&p1, root);
    root = AddContact(&p2, root);
    root = AddContact(&p3, root);
    
    TreeNode* min = FindMin(root);
    ck_assert_ptr_nonnull(min);
    ck_assert_str_eq(min->data->lastName, "Anderson");
    
    DeleteTree(root);
}
END_TEST

Suite* phone_book_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("PhoneBook");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_create_node);
    tcase_add_test(tc_core, test_add_contact);
    tcase_add_test(tc_core, test_print_empty_tree);
    tcase_add_test(tc_core, test_delete_contact);
    tcase_add_test(tc_core, test_edit_contact);
    tcase_add_test(tc_core, test_find_min);
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = phone_book_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}