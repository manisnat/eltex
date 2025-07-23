#include <stdio.h>
#include <stdarg.h>
#include "complex_calculator.h"

int main(void)
{   
    int (*ptr_func[4]) (double*, int, ...) = {add, sub, mult, divide};
    int calc = 0;
    printf("1. Сложение.\n2. Вычитание.\n3. Умножение.\n4. Деление.\nНомер операции: ");
    scanf("%d", &calc);
    int count = 0, res = 0;
    double result = 0;
    double nums[6];
    if (calc == 1 || calc == 2 || calc == 3 || calc == 4)
    {
        printf("Количество аргументов (от 1 до 6): ");
        scanf("%d", &count);
        if (count < 1 || count > 6)
        {
            printf("Неправильный диапазон чисел\n");
            return 1;
        }
        print_nums(count, nums);
    }
    switch (count)
    {
        case 1:
            res = ptr_func[calc - 1](&result, count, nums[0]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        case 2:
            res = ptr_func[calc - 1](&result, count, nums[0], nums[1]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        case 3:
            res = ptr_func[calc - 1](&result, count, nums[0], nums[1], nums[2]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        case 4:
            res = ptr_func[calc - 1](&result, count, nums[0], nums[1], nums[2], nums[3]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        case 5:
            res = ptr_func[calc - 1](&result, count, nums[0], nums[1], nums[2], nums[3], nums[4]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        case 6:
            res = ptr_func[calc - 1](&result, count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
            if (res == -1)
            {
                printf("Ошибка: деление на ноль!\n");
            } else {
                printf("%f \n", result);
            }
            break;
        default:
            printf("Неправильный диапазон чисел");
            break;
    }
       
    return 0;
}