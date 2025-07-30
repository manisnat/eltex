#include <check.h>
#include "ip.h"  

START_TEST(test_inet_pton_and_ntohl) {
    uint32_t result;
    
    // Корректный IP
    ck_assert_int_eq(inet_pton_and_ntohl("192.168.1.1", &result), 0);
    ck_assert_uint_eq(result, 0xC0A80101);
    
    // Неверный IP
    ck_assert_int_eq(inet_pton_and_ntohl("300.168.1.1", &result), 1);
}
END_TEST

START_TEST(test_rand_ip) {
    uint32_t ip;
    char ip_str[INET_ADDRSTRLEN];
    
    srand(42);  // Фиксируем seed для воспроизводимости
    
    rand_ip(&ip, ip_str);
    
    // Проверяем корректность формата IP
    struct in_addr addr;
    ck_assert_int_eq(inet_pton(AF_INET, ip_str, &addr), 1);
    
    // Проверяем, что все октеты в допустимом диапазоне
    ck_assert_uint_ge(ip >> 24, 0);
    ck_assert_uint_le(ip >> 24, 255);
    ck_assert_uint_ge((ip >> 16) & 0xFF, 0);
    ck_assert_uint_le((ip >> 16) & 0xFF, 255);
    ck_assert_uint_ge((ip >> 8) & 0xFF, 0);
    ck_assert_uint_le((ip >> 8) & 0xFF, 255);
    ck_assert_uint_ge(ip & 0xFF, 0);
    ck_assert_uint_le(ip & 0xFF, 255);
}
END_TEST

START_TEST(test_ip_and_mask) {
    // Проверка обычного случая
    ck_assert_uint_eq(ip_and_mask(0xC0A80101, 0xFFFFFF00), 0xC0A80100);
    
    // Проверка полной маски
    ck_assert_uint_eq(ip_and_mask(0xC0A80101, 0xFFFFFFFF), 0xC0A80101);
    
    // Проверка нулевой маски
    ck_assert_uint_eq(ip_and_mask(0xC0A80101, 0x00000000), 0x00000000);
}
END_TEST

START_TEST(test_subnet_check) {
    // Тестируем определение подсети
    ck_assert(ip_and_mask(0xC0A80101, 0xFFFFFF00) == 
              ip_and_mask(0xC0A80102, 0xFFFFFF00));  // Должны быть в одной подсети
    
    ck_assert(ip_and_mask(0xC0A80101, 0xFFFFFF00) != 
              ip_and_mask(0xC0A80201, 0xFFFFFF00));  // Разные подсети
}
END_TEST

Suite *ip_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("IP");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_inet_pton_and_ntohl);
    tcase_add_test(tc_core, test_rand_ip);
    tcase_add_test(tc_core, test_ip_and_mask);
    tcase_add_test(tc_core, test_subnet_check);
    
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = ip_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}