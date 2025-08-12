#include "phone_book.h"

int main()
{
    Item book;
    Snake list;
    Init(&list);

    while (1)
    {
        char count[2];
        printf("\n1. Добавить контакт\n2. Показать все контакты\n3. Изменить контакт\n4. Удалить контакт\n5. Удалить всю телефонную книгу\n6. Выход\nВведите команду: ");
        scanf("%1s", count);
        switch(count[0])
        {
            case '1':
                Person p;
                int flag1 = ScanfContact(&p);
                if (flag1) 
                {
                    printf("\nНеправильно создан контакт! Поле Имя и Фамилия обязательны!\n");
                    
                } else
                {
                    AddContact(&p, &list);
                }
                PrintContacts(&list);
                break;
            case '2':
                PrintContacts(&list);
                break;
            case '3':
                if (list.head == NULL)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                PrintContacts(&list);
                char last_name1[MAX_LENGTH];
                char first_name1[MAX_LENGTH];
                printf("\nВыберите контакт для изменения:\nВведите фамилию: ");
                scanf("%29s", last_name1);
                printf("Введите имя: ");
                scanf("%29s", first_name1);
                Person people;
                ScanfEditContact(&people);
                int flag3 = EditContact(&list, &people, last_name1, first_name1);
                if (flag3 == 1) printf("\nТелефонная книга пуста!\n");
                if (flag3 == -1) printf("\nНет такого контакта!\n");
                if (flag3 == 0) PrintContacts(&list);
                break;
            case '4':
                if (list.head == NULL)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                PrintContacts(&list);
                char last_name2[MAX_LENGTH];
                char first_name2[MAX_LENGTH];
                printf("\nВыберите контакт для удаления:\nВведите фамилию: ");
                scanf("%29s", last_name2);
                printf("Введите имя: ");
                scanf("%29s", first_name2);

                int flag4 = DeleteContact(&list, last_name2, first_name2);
                if (flag4 == 1) printf("\nТелефонная книга пуста!\n");
                if (flag4 == -1) printf("\nНет такого контакта!\n");
                if (flag4 == 0) PrintContacts(&list);
                break;
            case '5':
                DeleteList(&list);
                PrintContacts(&list);
                break;
            case '6':
                exit(0);
            default:
                printf("\nТакой команды не существует!\n");
                break;
        }

    }

    DeleteList(&list);
    return 0;
}