#include <stdio.h>
#include <stdarg.h>
#include "complex_calculator.h"
 

int add(double *result, int num_args, ...)
{
    *result = 0;
    if (num_args < 1) return 1;
    va_list args;         
    va_start(args, num_args);    
    for (int i = 0; i < num_args; i++)
    {
        *result += va_arg(args, double);
    }
    va_end(args);
    return 0;
}

int sub(double *result, int num_args, ...)
{
    if (num_args < 1) return 1;
    va_list args;         
    va_start(args, num_args); 
    *result = va_arg(args, double);   
    for (int i = 1; i < num_args; i++)
    {
        *result -= va_arg(args, double);
    }
    va_end(args);
    return 0;
}

int mult(double *result, int num_args, ...)
{
    if (num_args < 1) return 1;
    va_list args;         
    va_start(args, num_args);  
    *result = va_arg(args, double);    
    for (int i = 1; i < num_args; i++)
    {
        *result *= va_arg(args, double);
    }
    va_end(args);
    return 0;
}

int divide(double *result, int num_args, ...)
{
    if (num_args < 1) return 1;
    va_list args;         
    va_start(args, num_args);  
    *result = va_arg(args, double);    
    for (int i = 1; i < num_args; i++)
    {
        double divisor = va_arg(args, double);
        if (divisor == 0)
        {
            va_end(args);
            return -1;
        }
        *result /= divisor;
    }
    va_end(args);
    return 0;
}

void print_nums(int count, double* nums)
{
    for (int i = 0; i < count; i++)
    {
        printf("Число %d: ", i+1);
        scanf("%lf", &nums[i]);
    }
}
    
 

    