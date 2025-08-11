#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

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

typedef struct TreeNode {
    Person* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(Person* p);
TreeNode* AddContact(Person* p, TreeNode* root);
int ScanfContact(Person *p);
int PrintContacts(TreeNode* root, int *counter);
int PrettyPrintTree(TreeNode* root, int level, int is_left);
int ScanfEditContact(Person *p);
TreeNode* EditContact(TreeNode* root, Person* new_data, char* last_name, char* first_name, int* found);
TreeNode* DeleteContact(TreeNode* root, char* last_name, char* first_name, int *found);
TreeNode* FindMin(TreeNode* node);
void DeleteTree(TreeNode* root);

#endif
