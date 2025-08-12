#include "phone_book.h"

int ScanfContact(Person *p)
{
    int flag = 0;
    printf("\nВведите фамилию: ");
    scanf("%29s", p->lastName);
    while (getchar() != '\n');

    printf("Введите имя: ");
    scanf("%29s", p->firstName);
    while (getchar() != '\n');

    if (strlen(p->firstName) == 0 || strlen(p->lastName) == 0) return 1;

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

int PrintContacts(Snake *list)
{
    if (list->head == NULL)
    {
        printf("\nТелефонная книга пуста!\n");
        return 1;
    }
    printf("\nСписок контактов:\n");
    int i = 1;
    for (Item* item = list->head; item != NULL; item = item->next)
    {
        printf("\n#%d\n", i);
        printf("Фамилия: %s\nИмя: %s\n", item->data->lastName, item->data->firstName);

        if (strlen(item->data->PlaceWork) > 0) printf("Место работы: %s\n", item->data->PlaceWork);
        if (strlen(item->data->jobTitle) > 0) printf("Должность: %s\n", item->data->jobTitle);
        if (strlen(item->data->workPhone) > 0) printf("Рабочий телефон: %s\n", item->data->workPhone);
        if (strlen(item->data->personalPhone) > 0) printf("Личный телефон: %s\n", item->data->personalPhone);
        if (strlen(item->data->emailAddress) > 0) printf("Почта: %s\n", item->data->emailAddress);
        if (strlen(item->data->telegram) > 0) printf("Telegram: %s\n", item->data->telegram);
        if (strlen(item->data->vkontakte) > 0) printf("VKontakte: %s\n", item->data->vkontakte);
        i++;
    }
    return 0;
}

int ScanfEditContact(Person *p)
{
    printf("\nВведите изменения для контакта:\n");
    int ch = getchar() != '\n';
    printf("Введите фамилию: ");
    fgets(p->lastName, MAX_LENGTH, stdin);
    p->lastName[strlen(p->lastName) - 1] = '\0';

    printf("Введите имя: ");
    fgets(p->firstName, MAX_LENGTH, stdin);
    p->firstName[strlen(p->firstName) - 1] = '\0';

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
