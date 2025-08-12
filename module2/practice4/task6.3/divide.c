#include <stdarg.h>

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

    
 

    
