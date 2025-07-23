#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 100
#define MAX_LENGTH 30

typedef struct {
    char firstName[MAX_LENGTH];
    char lastName[MAX_LENGTH];
    char PlaceWork[MAX_LENGTH];
    char jobTitle[MAX_LENGTH];
    char workPhone[MAX_LENGTH];
    char personalPhone[MAX_LENGTH];
    char emailAddress[MAX_LENGTH];
    char telegram[MAX_LENGTH];
    char vkontakte[MAX_LENGTH];
} Person;

typedef struct {
    Person* data;
    int size;
    int capacity;
} PhoneBook;

int InitBook(PhoneBook *list, int capacity);
int AddContact(PhoneBook *book, Person *person);
int ScanfContact(Person *p);
int PrintContacts(PhoneBook *book);
int ScanfEditContact(Person *p);
int EditContact(PhoneBook* book, Person* p, int id);
int DeleteContact(PhoneBook *book, int id);

#endif
