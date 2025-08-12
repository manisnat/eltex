#include <stdarg.h>
 
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

    
