#include <stdio.h>
#include <stdarg.h>
#include "simple_calculator.h"
 
double add(int num_args, ...)
{
    double result = 0;
    va_list args;         
    va_start(args, num_args);    
    for (int i = 0; i < num_args; i++)
    {
        result += va_arg(args, double);
    }
    va_end(args);
    return result;
}

double sub(int num_args, ...)
{
    va_list args;         
    va_start(args, num_args); 
    double result = va_arg(args, double);   
    for (int i = 1; i < num_args; i++)
    {
        result -= va_arg(args, double);
    }
    va_end(args);
    return result;
}

double mult(int num_args, ...)
{
    va_list args;         
    va_start(args, num_args);  
    double result = va_arg(args, double);    
    for (int i = 1; i < num_args; i++)
    {
        result *= va_arg(args, double);
    }
    va_end(args);
    return result;
}

int div(double *result, int num_args, ...)
{
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
    
 

    