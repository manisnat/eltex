#include "list.h"

void Init(Snake* list)
{
    list->head = NULL;
    list->tail = NULL;
}

Item* AddContact(Person* p, Snake* list) {
    Item* item = malloc(sizeof(Item));
    item->data = malloc(sizeof(Person));
    *item->data = *p;
    item->next = NULL;
    item->prev = NULL;


    if (list->head == NULL) 
    {
        list->head = item;
        list->tail = item;
        return item;
    }
    
    if (strcmp(p->lastName, list->head->data->lastName) < 0 || (strcmp(p->lastName, list->head->data->lastName) == 0 && strcmp(p->firstName, list->head->data->firstName) < 0))
    {
        item->next = list->head;
        list->head->prev = item;
        list->head = item;
        return item;
    }

    Item* tmp = list->head;
    while (tmp->next != NULL)
    {
        if (strcmp(p->lastName, tmp->next->data->lastName) < 0 || (strcmp(p->lastName, tmp->next->data->lastName) == 0 && strcmp(p->firstName, tmp->next->data->firstName) < 0))
        {
            item->next = tmp->next;
            item->prev = tmp;
            tmp->next->prev = item;
            tmp->next = item;
            return item;
        }
        tmp = tmp->next;
    }
    tmp->next = item;
    item->prev = tmp;
    list->tail = item;
    return item;
}

int EditContact(Snake* list, Person* p, char* last_name, char* first_name)
{
    if (list->head == NULL) return 1;

    for(Item* tmp = list->head; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(last_name, tmp->data->lastName) == 0 && strcmp(first_name, tmp->data->firstName) == 0)
        {
            
            if (strlen(p->lastName) > 0) strcpy(tmp->data->lastName, p->lastName);
            if (strlen(p->firstName) > 0) strcpy(tmp->data->firstName, p->firstName);
            if (strlen(p->PlaceWork) > 0) strcpy(tmp->data->PlaceWork, p->PlaceWork);
            if (strlen(p->jobTitle) > 0) strcpy(tmp->data->jobTitle, p->jobTitle);
            if (strlen(p->workPhone) > 0) strcpy(tmp->data->workPhone, p->workPhone);
            if (strlen(p->personalPhone) > 0) strcpy(tmp->data->personalPhone, p->personalPhone);
            if (strlen(p->emailAddress) > 0) strcpy(tmp->data->emailAddress, p->emailAddress);
            if (strlen(p->telegram) > 0) strcpy(tmp->data->telegram, p->telegram);
            if (strlen(p->vkontakte) > 0) strcpy(tmp->data->vkontakte, p->vkontakte);

            if (strcmp(last_name, tmp->data->lastName) != 0 || strcmp(first_name, tmp->data->firstName) != 0)
            {
                Person* personData = tmp->data;
                
                if (tmp->prev) tmp->prev->next = tmp->next;
                else list->head = tmp->next;

                if (tmp->next) tmp->next->prev = tmp->prev;
                else list->tail = tmp->prev;

                free(tmp);
                
                AddContact(personData, list);
            }
            return 0;
        } 
    } 
    return -1;

}

int DeleteContact(Snake* list, char* last_name, char* first_name) {
    if (list->head == NULL) return 1;

    Item* tmp = list->head;
    if (strcmp(tmp->data->lastName, last_name) == 0 && strcmp(tmp->data->firstName, first_name) == 0)
    {
        list->head = tmp->next;
        free(tmp->data);
        free(tmp);
        return 0;
    }

    while (tmp->next != NULL)
    {
        if (strcmp(tmp->data->lastName, last_name) == 0 && strcmp(tmp->data->firstName, first_name) == 0)
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            free(tmp->data);
            free(tmp);
            return 0;
        }
        tmp = tmp->next;
    }

    if (strcmp(tmp->data->lastName, last_name) == 0 && strcmp(tmp->data->firstName, first_name) == 0)
    {
        tmp->prev->next = NULL;
        list->tail = tmp->prev;
        free(tmp->data);
        free(tmp);
        return 0;
    }

    return -1;
}

void DeleteList(Snake* list) {
    for(Item* item = list->head; item != NULL; item = list->head) {
        list->head = list->head->next;
        free(item->data);
        free(item);
    }
    list->head = NULL;
    list->tail = NULL;
}
