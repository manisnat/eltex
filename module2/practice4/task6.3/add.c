#include <stdarg.h>
 

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

