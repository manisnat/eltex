#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 30

typedef struct {
    char lastName[MAX_LENGTH];
    char firstName[MAX_LENGTH];
    char PlaceWork[MAX_LENGTH];
    char jobTitle[MAX_LENGTH];
    char workPhone[MAX_LENGTH];
    char personalPhone[MAX_LENGTH];
    char emailAddress[MAX_LENGTH];
    char telegram[MAX_LENGTH];
    char vkontakte[MAX_LENGTH];
} Person;

typedef struct Item {
    Person* data;
    struct Item* next;
    struct Item* prev;
} Item;

typedef struct {
    Item* head;
    Item* tail;
} Snake;

void Init(Snake* list);
Item* AddContact(Person* p, Snake* list);
int EditContact(Snake* list, Person* p, char* last_name, char* first_name);
int DeleteContact(Snake* list, char* last_name, char* first_name);
void DeleteList(Snake* list);

#endif
