#include <stdio.h>
#include <assert.h>
#include "simple_calculator.h"

void test_add() {
    printf("Testing add()...\n");
    assert(add(1, 5.0) == 5.0);
    assert(add(2, 3.5, 2.5) == 6.0);
    assert(add(3, 1.1, 2.2, 3.3) == 6.6);
    printf("add() tests passed!\n");
}

void test_sub() {
    printf("Testing sub()...\n");
    assert(sub(2, 10.0, 2.5) == 7.5);
    assert(sub(4, 20.0, 5.0, 3.0, 2.0) == 10.0);
    printf("sub() tests passed!\n");
}

void test_mult() {
    printf("Testing mult()...\n");
    assert(mult(1, 5.0) == 5.0);
    assert(mult(2, 3.0, 2.5) == 7.5);
    assert(mult(3, 1.0, 2.0, 3.0) == 6.0);
    printf("mult() tests passed!\n");
}

void test_div() {
    printf("Testing div()...\n");
    double result;
    
    // Успешное деление
    assert(div(&result, 2, 10.0, 2.0) == 0);
    assert(result == 5.0);
    
    // Деление на ноль
    assert(div(&result, 2, 10.0, 0.0) == -1);
    
    printf("div() tests passed!\n");
}

int main() {
    test_add();
    test_sub();
    test_mult();
    test_div();
    
    printf("\nAll tests passed successfully!\n");
    return 0;
}