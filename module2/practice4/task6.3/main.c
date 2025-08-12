#include <stdio.h>    
#include <dlfcn.h>    
#include <string.h>   


typedef int (*operation_func)(double*, int, ...);


typedef struct {
    void* handle;          
    operation_func func;       
} Operation;


void print_nums(int count, double* nums) {
    for (int i = 0; i < count; i++) {
        printf("Число %d: ", i+1);  
        scanf("%lf", &nums[i]);     
    }
}

void cleanup(Operation* operations)
{
    for (int i = 0; i < 4; i++) {
        if (operations[i].handle) 
            dlclose(operations[i].handle);
    }
}

int main() {
    Operation operations[4];  
    char* op_names[] = {"add", "sub", "mult", "divide"}; 
    int calc = 0;            
    double nums[6];          
    double result = 0;       
    int count = 0;           

    for (int i = 0; i < 4; i++) {
        char lib_path[50];  
        
        snprintf(lib_path, sizeof(lib_path), "libs/lib%s.so", op_names[i]);
        
        operations[i].handle = dlopen(lib_path, RTLD_LAZY);
        if (!operations[i].handle) {
            fprintf(stderr, "Ошибка загрузки %s: %s\n", lib_path, dlerror());
            return 1;
        }
        
        operations[i].func = (operation_func)dlsym(operations[i].handle, op_names[i]);
        if (!operations[i].func) {
            fprintf(stderr, "Ошибка поиска функции %s: %s\n", op_names[i], dlerror());
            dlclose(operations[i].handle);
            return 1;
        }
        
    }

    printf("1. Сложение\n2. Вычитание\n3. Умножение\n4. Деление\nНомер операции: ");
    scanf("%d", &calc);  
    
    if (calc < 1 || calc > 4) {
        printf("Неверная операция\n");
        cleanup(operations); 
        return 1;
    }

    printf("Количество аргументов (1-6): ");
    scanf("%d", &count);
    
    if (count < 1 || count > 6) {
        printf("Неверное количество аргументов\n");
        cleanup(operations);
        return 1;
    }
    
    print_nums(count, nums);

    int res = 0;  
    switch(count) {
        case 1: 
            res = operations[calc-1].func(&result, count, nums[0]); 
            break;
        case 2:
            res = operations[calc-1].func(&result, count, nums[0], nums[1]);
            break;
        case 3:
            res = operations[calc-1].func(&result, count, nums[0], nums[1], nums[2]);
            break;
        case 4:
            res = operations[calc-1].func(&result, count, nums[0], nums[1], nums[2], nums[3]);
            break;
        case 5:
            res = operations[calc-1].func(&result, count, nums[0], nums[1], nums[2], nums[3], nums[4]);
            break;
        case 6:
            res = operations[calc-1].func(&result, count, nums[0], nums[1], nums[2], nums[3], nums[4], nums[5]);
            break;
    }

    if (res == -1) {
        printf("Ошибка: деление на ноль!\n");
    } else if (res != 0) {
        printf("Ошибка выполнения операции\n");
    } else {
        printf("Результат: %f\n", result);
    }

    return 0;
}