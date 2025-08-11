#include "phone_book.h"

int main()
{
    TreeNode* root = NULL;

    while (1)
    {
        char count[2];
        printf("\n1. Добавить контакт\n2. Показать все контакты\n3. Показать дерево\n4. Изменить контакт\n5. Удалить контакт\n6. Удалить всю телефонную книгу\n7. Выход\nВведите команду: ");
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
                    root = AddContact(&p, root);
                }
                int i = 1;
                PrintContacts(root, &i);
                printf("\n");
                PrettyPrintTree(root, 0, 0);
                break;
            case '2':
                i = 1;
                PrintContacts(root, &i);
                break;
            case '3':
                printf("\n");
                PrettyPrintTree(root, 0, 0);
                break;
            case '4':
                if (root == NULL)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                i = 1;
                PrintContacts(root, &i);
                char last_name1[MAX_LENGTH];
                char first_name1[MAX_LENGTH];
                printf("\nВыберите контакт для изменения:\nВведите фамилию: ");
                scanf("%29s", last_name1);
                printf("Введите имя: ");
                scanf("%29s", first_name1);
                Person people;
                ScanfEditContact(&people);
                int found1 = 0;
                root = EditContact(root, &people, last_name1, first_name1, &found1);
                if (!found1) printf("\nНет такого контакта!!\n");
                i = 1;
                PrintContacts(root, &i);
                printf("\n");
                PrettyPrintTree(root, 0, 0);
                break;
            case '5':
                if (root == NULL)
                {
                    printf("\nТелефонная книга пуста!\n");
                    break;
                }
                i = 1;
                PrintContacts(root, &i);
                char last_name2[MAX_LENGTH];
                char first_name2[MAX_LENGTH];
                printf("\nВыберите контакт для удаления:\nВведите фамилию: ");
                scanf("%29s", last_name2);
                printf("Введите имя: ");
                scanf("%29s", first_name2);

                int found2 = 0;
                root = DeleteContact(root, last_name2, first_name2, &found2);
                if (!found2) printf("\nНет такого контакта!\n");
                i = 1;
                PrintContacts(root, &i);
                break;
            case '6':
                DeleteTree(root);
                root = NULL;
                i = 1;
                PrintContacts(root, &i);
                break;
            case '7':
                exit(0);
            default:
                printf("\nТакой команды не существует!\n");
                break;
        }

    }

    DeleteTree(root);
    return 0;
}