#include <stdio.h>
#include <stdarg.h>
#include "simple_calculator.h"

int main(void)
{   
    int calc = 0;
    printf("1. Сложение.\n2. Вычитание.\n3. Умножение.\n4. Деление.\nНомер операции: ");
    scanf("%d", &calc);
    int count = 0, res = 0;
    double result;
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
    switch (calc)
    {
        case 1:
            switch (count)
            {
                case 1:
                    printf("%.2f \n", add(count, nums[0]));
                    break;
                case 2:
                    printf("%.2f \n", add(count, nums[0], nums[1]));
                    break;
                case 3:
                    printf("%.2f \n", add(count, nums[0], nums[1], nums[2]));
                    break;
                case 4:
                    printf("%.2f \n", add(count, nums[0], nums[1], nums[2], nums[3]));
                    break;
                case 5:
                    printf("%.2f \n", add(count, nums[0], nums[1], nums[2], nums[3], nums[4]));
                    break;
                case 6:
                    printf("%.2f \n", add(count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]));
                    break;
                default:
                    printf("Неправильный диапазон чисел");
                    break;
            }
            break;
        case 2:
            switch (count)
            {
                case 1:
                    printf("%.2f \n", sub(count, nums[0]));
                    break;
                case 2:
                    printf("%.2f \n", sub(count, nums[0], nums[1]));
                    break;
                case 3:
                    printf("%.2f \n", sub(count, nums[0], nums[1], nums[2]));
                    break;
                case 4:
                    printf("%.2f \n", sub(count, nums[0], nums[1], nums[2], nums[3]));
                    break;
                case 5:
                    printf("%.2f \n", sub(count, nums[0], nums[1], nums[2], nums[3], nums[4]));
                    break;
                case 6:
                    printf("%.2f \n", sub(count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]));
                    break;
                default:
                    printf("Неправильный диапазон чисел");
                    break;
            }
            break;
        case 3:
            switch (count)
            {
                case 1:
                    printf("%.2f \n", mult(count, nums[0]));
                    break;
                case 2:
                    printf("%.2f \n", mult(count, nums[0], nums[1]));
                    break;
                case 3:
                    printf("%.2f \n", mult(count, nums[0], nums[1], nums[2]));
                    break;
                case 4:
                    printf("%.2f \n", mult(count, nums[0], nums[1], nums[2], nums[3]));
                    break;
                case 5:
                    printf("%.2f \n", mult(count, nums[0], nums[1], nums[2], nums[3], nums[4]));
                    break;
                case 6:
                    printf("%.2f \n", mult(count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]));
                    break;
                default:
                    printf("Неправильный диапазон чисел");
                    break;
            }
            break;
        case 4:
            switch (count)
            {
                case 1:
                    res = div(&result, count, nums[0]);
                    if (res == -1)
                    {
                        printf("Ошибка: деление на ноль!\n");
                    } else {
                        printf("%f \n", result);
                    }
                    break;
                case 2:
                    res = div(&result, count, nums[0], nums[1]);
                    if (res == -1)
                    {
                        printf("Ошибка: деление на ноль!\n");
                    } else {
                        printf("%f \n", result);
                    }
                    break;
                case 3:
                    res = div(&result, count, nums[0], nums[1], nums[2]);
                    if (res == -1)
                    {
                        printf("Ошибка: деление на ноль!\n");
                    } else {
                        printf("%f \n", result);
                    }
                    break;
                case 4:
                    res = div(&result, count, nums[0], nums[1], nums[2], nums[3]);
                    if (res == -1)
                    {
                        printf("Ошибка: деление на ноль!\n");
                    } else {
                        printf("%f \n", result);
                    }
                    break;
                case 5:
                    res = div(&result, count, nums[0], nums[1], nums[2], nums[3], nums[4]);
                    if (res == -1)
                    {
                        printf("Ошибка: деление на ноль!\n");
                    } else {
                        printf("%f \n", result);
                    }
                    break;
                case 6:
                    res = div(&result, count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
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
            break;

        default:
            printf("Нет такой операции\n");
            break;
    }
    return 0;
}