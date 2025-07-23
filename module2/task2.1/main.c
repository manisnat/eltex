#include "phone_book.h"

int main()
{
    PhoneBook book;
    InitBook(&book, CAPACITY);

    while (1)
    {
        char count;
        printf("\n1. Добавить контакт\n2. Показать все контакты\n3. Изменить контакт\n4. Удалить контакт\n5. Выход\nВведите команду: ");
        scanf("%c", &count);
        switch(count)
        {
            case '1':
                Person p;
                int flag1 = ScanfContact(&p);
                if (flag1) printf("\nНеправильно создан контакт! Поле Имя и Фамилия обязательны!\n");
                int flag2 = AddContact(&book, &p);
                if (flag2) printf("\nНевозможно добавить контакт, телефонная книга переполнена!\n");
                break;
            case '2':
                PrintContacts(&book);
                break;
            case '3':
                if (book.size == 0)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                PrintContacts(&book);
                int id1 = 0;
                printf("\nВведи номер контакта, который хотите изменить: ");
                scanf("%d", &id1);
                Person people;
                ScanfEditContact(&people);
                int flag3 = EditContact(&book, &people, id1-1);
                if (flag3 == 1) printf("\nТелефонная книга пуста!\n");
                if (flag3 == -1) printf("\nНеправильно введён номер контакта!\n");
                if (flag3 == 0) PrintContacts(&book);
                break;
            case '4':
                if (book.size == 0)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                PrintContacts(&book);
                int id2 = 0;
                printf("\nВведи номер контакта, который хотите удалить: ");
                scanf("%d", &id2);
                int flag4 = DeleteContact(&book, id2-1);
                if (flag4 == 1) printf("\nТелефонная книга пуста!\n");
                if (flag4 == -1) printf("\nНеправильно введён номер контакта!\n");
                if (flag4 == 0) PrintContacts(&book);
                break;
            case '5':
                exit(0);
            default:
                printf("\nТакой команды не существует!\n");
                break;
        }

    }

    free(book.data);
    return 0;
}