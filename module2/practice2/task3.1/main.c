#include "chmod.h"

int main()
{
    char letters[10];
    int octal = 0;
    while (1)
    {
        printf("\n1. Преобразование из буквенного вида (rwx) в цифровой (755)\n");
        printf("2. Преобразование из цифрового вида (755) в буквенный (rwx)\n");
        printf("3. Узнать права доступа у файла\n");
        printf("4. Изменить права доступа\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");
        int num = 0;
        scanf("%d", &num);
        switch(num)
        {
            case 1:
                printf("\nВведите права вида (rwxrwxrwx): ");
                scanf("%s", letters);
                octal = letters_in_octal(letters);
                if (octal != -1) 
                {
                    printf("Цифровой вид: %o\n", octal);
                    print_binary(octal);
                } else printf("\nНеправильно введены права!\n");
                break;
            case 2:
                printf("\nВведите права вида (755): ");
                scanf("%o", &octal);
                if (!octal_in_letters(octal, letters))
                {
                    printf("Буквенный вид: %s\n", letters);
                    print_binary(octal);
                } else printf("\nНеправильно введены права!\n");
                break;
            case 3:
                char name[20];
                printf("\nВведите имя файла: ");
                scanf("%s", name);
                int flag = stat_file(name, &octal);
                if (!flag) {
                    printf("Права доступа в цифровом формате: %o\n", octal);
                    octal_in_letters(octal, letters);
                    printf("Буквенный вид: %s\n", letters);
                    print_binary(octal);
                } else {
                    perror("Ошибка");
                }
                break;
            case 4:
                if (octal == 0)
                {
                    printf("\nСначала установите права (пункты 1, 2 или 3)\n");
                    break;
                }
                printf("\nИзначальный вид прав:\n");
                printf("Цифровой: %o\n", octal);
                printf("Буквенный: %s\n", letters);
                char buffer[10];
                printf("\nВведите изменения для прав (например, ug+rw): ");
                scanf("%s", buffer);
                edit_right(buffer, &octal);
                printf("\nИзменённые права:\nЦифровой вид: %o\n", octal);
                octal_in_letters(octal, letters);
                print_binary(octal);
                printf("Буквенный вид: %s\n", letters);
                break;
            case 5:
                exit(0);
            default:
                printf("\nНет такой комбинации!\n");
                break;

        }
    }


    return 0;
}