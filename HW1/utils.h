#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } boolean;

struct Node
{
    int data;
    struct Node *next;
};

struct Student
{
    int number;
    char name[50];
    int age;
    struct Student *next;
};

struct Node *head = NULL;

extern void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

extern void printStudentList(struct Student *node)
{
    int i = 1;
    while (node != NULL)
    {
        printf("%d- %d %s %d\n",i, node->number, node->name, node->age);
        node = node->next;
        i++;
    }
}

extern void pushToList(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

extern void appendToList(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

extern void sortList(struct Node **head_ref)
{
    struct Node *temp = *head_ref;
    struct Node *temp2 = *head_ref;
    int tempData;
    while (temp != NULL)
    {
        while (temp2 != NULL)
        {
            if (temp->data < temp2->data)
            {
                tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp2 = *head_ref;
        temp = temp->next;
    }
}

extern void addStudentToList(struct Student **head_ref, int number, char *name, int age)
{
    struct Student *new_node = (struct Student *)malloc(sizeof(struct Student));
    new_node->number = number;
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->next = *head_ref;
    *head_ref = new_node;
}