#include "phone_book.h"


int InitBook(PhoneBook *list, int capacity)
{
    int flag = 0;
    list->data = malloc(capacity * sizeof(Person));
    if (list->data == NULL) flag = 1;
    if (!flag)
    {
        list->size = 0;
        list->capacity = capacity;
    }
    return flag;
}

int AddContact(PhoneBook *book, Person *person)
{
    int flag = 0;
    if (book->size >= book->capacity) flag = 1;
    if (!flag)
    {
        book->data[book->size] = *person;
        book->size++;
    }
    return flag;
}

int ScanfContact(Person *p)
{
    int flag = 0;
    printf("\nВведите имя: ");
    scanf("%29s", p->firstName);
    printf("Введите фамилию: ");
    scanf("%29s", p->lastName);

    if (p->firstName != NULL && p->lastName){
        int ch = getchar() != '\n';

        printf("Введите место работы: ");
        fgets(p->PlaceWork, MAX_LENGTH, stdin);
        p->PlaceWork[strlen(p->PlaceWork) - 1] = '\0';

        printf("Введите должность: ");
        fgets(p->jobTitle, MAX_LENGTH, stdin);
        p->jobTitle[strlen(p->jobTitle) - 1] = '\0';

        printf("Введите рабочий телефон: ");
        fgets(p->workPhone, MAX_LENGTH, stdin);
        p->workPhone[strlen(p->workPhone) - 1] = '\0';

        printf("Введите личный телефон: ");
        fgets(p->personalPhone, MAX_LENGTH, stdin);
        p->personalPhone[strlen(p->personalPhone) - 1] = '\0';
        
        printf("Введите почту: ");
        fgets(p->emailAddress, MAX_LENGTH, stdin);
        p->emailAddress[strlen(p->emailAddress) - 1] = '\0';
        
        printf("Введите ссылку на телеграм: ");
        fgets(p->telegram, MAX_LENGTH, stdin);
        p->telegram[strlen(p->telegram) - 1] = '\0';

        printf("Введите ссылку на вконтакте: ");
        fgets(p->vkontakte, MAX_LENGTH, stdin);
        p->vkontakte[strlen(p->vkontakte) - 1] = '\0';
    } else flag = 1;

    return flag;
}

int PrintContacts(PhoneBook *book)
{
    if (book->size == 0)
    {
        printf("\nТелефонная книга пуста!\n");
    }
    printf("\nСписок контактов:\n");
    for (int i = 0; i < book->size; i++)
    {
        printf("\n#%d\n", i+1);
        printf("Имя: %s\nФамилия: %s\n", book->data[i].firstName, book->data[i].lastName);

        if (strlen(book->data[i].PlaceWork) > 0) printf("Место работы: %s\n", book->data[i].PlaceWork);
        if (strlen(book->data[i].jobTitle) > 0) printf("Должность: %s\n", book->data[i].jobTitle);
        if (strlen(book->data[i].workPhone) > 0) printf("Рабочий телефон: %s\n", book->data[i].workPhone);
        if (strlen(book->data[i].personalPhone) > 0) printf("Личный телефон: %s\n", book->data[i].personalPhone);
        if (strlen(book->data[i].emailAddress) > 0) printf("Почта: %s\n", book->data[i].emailAddress);
        if (strlen(book->data[i].telegram) > 0) printf("Telegram: %s\n", book->data[i].telegram);
        if (strlen(book->data[i].vkontakte) > 0) printf("VKontakte: %s\n", book->data[i].vkontakte);

    }
}

int ScanfEditContact(Person *p)
{
    int ch = getchar() != '\n';
    printf("Введите имя: ");
    fgets(p->firstName, MAX_LENGTH, stdin);
    p->firstName[strlen(p->firstName) - 1] = '\0';

    printf("Введите фамилию: ");
    fgets(p->lastName, MAX_LENGTH, stdin);
    p->lastName[strlen(p->lastName) - 1] = '\0';

    printf("Введите место работы: ");
    fgets(p->PlaceWork, MAX_LENGTH, stdin);
    p->PlaceWork[strlen(p->PlaceWork) - 1] = '\0';

    printf("Введите должность: ");
    fgets(p->jobTitle, MAX_LENGTH, stdin);
    p->jobTitle[strlen(p->jobTitle) - 1] = '\0';

    printf("Введите рабочий телефон: ");
    fgets(p->workPhone, MAX_LENGTH, stdin);
    p->workPhone[strlen(p->workPhone) - 1] = '\0';

    printf("Введите личный телефон: ");
    fgets(p->personalPhone, MAX_LENGTH, stdin);
    p->personalPhone[strlen(p->personalPhone) - 1] = '\0';
            
    printf("Введите почту: ");
    fgets(p->emailAddress, MAX_LENGTH, stdin);
    p->emailAddress[strlen(p->emailAddress) - 1] = '\0';
            
    printf("Введите ссылку на телеграм: ");
    fgets(p->telegram, MAX_LENGTH, stdin);
    p->telegram[strlen(p->telegram) - 1] = '\0';

    printf("Введите ссылку на вконтакте: ");
    fgets(p->vkontakte, MAX_LENGTH, stdin);
    p->vkontakte[strlen(p->vkontakte) - 1] = '\0';

    return 0;
}

int EditContact(PhoneBook* book, Person* p, int id)
{
    int flag = 0;
    if (id >= book->size || id < 0) flag = -1;
    if (book->size == 0) flag = 1;

    if (flag == 0)
    {
        if (strlen(p->firstName) > 0) strcpy(book->data[id].firstName, p->firstName);
        if (strlen(p->lastName) > 0) strcpy(book->data[id].lastName, p->lastName);
        if (strlen(p->PlaceWork) > 0) strcpy(book->data[id].PlaceWork, p->PlaceWork);
        if (strlen(p->jobTitle) > 0) strcpy(book->data[id].jobTitle, p->jobTitle);
        if (strlen(p->workPhone) > 0) strcpy(book->data[id].workPhone, p->workPhone);
        if (strlen(p->personalPhone) > 0) strcpy(book->data[id].personalPhone, p->personalPhone);
        if (strlen(p->emailAddress) > 0) strcpy(book->data[id].emailAddress, p->emailAddress);
        if (strlen(p->telegram) > 0) strcpy(book->data[id].telegram, p->telegram);
        if (strlen(p->vkontakte) > 0) strcpy(book->data[id].vkontakte, p->vkontakte);
    }

    return flag;
}

int DeleteContact(PhoneBook *book, int id) 
{
    int flag = 0;
    if (id >= book->size || id < 0) flag = -1;
    if (book->size == 0) flag = 1;
    if (!flag)
    {
        for (int i = id; i < book->size; i++)
        {
            book->data[i] = book->data[i+1];
        }
        book->size--;
    }
    return flag;
}


