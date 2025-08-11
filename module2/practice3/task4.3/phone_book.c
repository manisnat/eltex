#include "phone_book.h"


TreeNode* createNode(Person* p)
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) exit(1);
    
    newNode->data = (Person*)malloc(sizeof(Person));
    if (newNode == NULL) 
    {
        free(newNode);
        exit(1);
    }

    *newNode->data = *p;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* AddContact(Person* p, TreeNode* root) {
    if (root == NULL)
    {
        return createNode(p);
    }

    if (strcmp(p->lastName, root->data->lastName) < 0 || (strcmp(p->lastName, root->data->lastName) == 0 && strcmp(p->firstName, root->data->firstName) < 0))
    {
        root->left = AddContact(p, root->left);
    } else if (strcmp(p->lastName, root->data->lastName) > 0 || (strcmp(p->lastName, root->data->lastName) == 0 && strcmp(p->firstName, root->data->firstName) > 0))
    {
        root->right = AddContact(p, root->right);
    } 

    return root;
}

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

int PrettyPrintTree(TreeNode* root, int level, int is_left) {
    if (root == NULL && level == 0 && is_left == 0)
    {
        printf("Телефонная книга пуста!\n");
        return 1;
    } else if (root == NULL) return 0;
 
    PrettyPrintTree(root->right, level + 1, 0);
 
    for (int i = 0; i < level - 1; i++) {
        printf("    ");
    }
    if (level > 0) {
        printf(is_left ? "└── " : "┌── ");
    }
 
    printf("\033[1;34m%s %s\033[0m\n", root->data->lastName, root->data->firstName);
 
    PrettyPrintTree(root->left, level + 1, 1);
    return 0;
}

int PrintContacts(TreeNode* root, int *counter)
{
    if (root == NULL)
    {
        printf("\nТелефонная книга пуста!\n");
        return 1;
    }

    if (root->left != NULL) PrintContacts(root->left, counter);
    
    if (*counter == 1) printf("\nСписок контактов:\n");
    printf("\n#%d\n", (*counter)++);
    printf("Фамилия: %s\nИмя: %s\n", root->data->lastName, root->data->firstName);

    if (strlen(root->data->PlaceWork) > 0) printf("Место работы: %s\n", root->data->PlaceWork);
    if (strlen(root->data->jobTitle) > 0) printf("Должность: %s\n", root->data->jobTitle);
    if (strlen(root->data->workPhone) > 0) printf("Рабочий телефон: %s\n", root->data->workPhone);
    if (strlen(root->data->personalPhone) > 0) printf("Личный телефон: %s\n", root->data->personalPhone);
    if (strlen(root->data->emailAddress) > 0) printf("Почта: %s\n", root->data->emailAddress);
    if (strlen(root->data->telegram) > 0) printf("Telegram: %s\n", root->data->telegram);
    if (strlen(root->data->vkontakte) > 0) printf("VKontakte: %s\n", root->data->vkontakte);

    if (root->right != NULL) PrintContacts(root->right, counter);
    
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

TreeNode* EditContact(TreeNode* root, Person* new_data, char* last_name, char* first_name, int* found) {
    if (root == NULL) {
        *found = 0;
        return NULL;
    }

    TreeNode* new_root = DeleteContact(root, last_name, first_name, found);
    if (!*found) {
        return root;
    }

    Person* contact_copy = (Person*)malloc(sizeof(Person));
    *contact_copy = *new_data;
    
    new_root = AddContact(contact_copy, new_root);
    
    free(contact_copy);
    return new_root;
}

TreeNode* DeleteContact(TreeNode* root, char* last_name, char* first_name, int* found) {
    if (root == NULL) 
    {
        *found = 0;
        return NULL;
    }

    int cmp_last = strcmp(last_name, root->data->lastName);
    int cmp_first = strcmp(first_name, root->data->firstName);

    if (cmp_last < 0 || (cmp_last == 0 && cmp_first < 0))
    {
        root->left = DeleteContact(root->left, last_name, first_name, found);
    } else if (cmp_last > 0 || (cmp_last == 0 && cmp_first > 0))
    {
        root->right = DeleteContact(root->right, last_name, first_name, found);
    } else
    {
        *found = 1;
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root->data);
            free(root);
            return temp;
        } else if (root->right == NULL)
        {
            TreeNode* temp = root->left;
            free(root->data);
            free(root);
            return temp;
        }

        TreeNode* min_right = FindMin(root->right);

        Person* new_data = (Person*)malloc(sizeof(Person));
        *new_data = *(min_right->data); 
            
        free(root->data);
            
        root->data = new_data;
            
        root->right = DeleteContact(root->right, min_right->data->lastName, min_right->data->firstName, found);
    }

    return root;
}

TreeNode* FindMin(TreeNode* node)
{
    while (node && node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

void DeleteTree(TreeNode* root) {
    if (root == NULL) return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    free(root->data);
    free(root);
}
