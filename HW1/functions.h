#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Utils Functions for making things easier
#include "utils.h"

/* 1 - Write a function that adds all odd numbers to the beginning of the list and all even
numbers to the end of the list until -1 is entered from the keyboard. */

extern void addNumbers()
{
    struct Node *head = NULL;
    int num;

    while (1)
    {
        printf("Enter number (-1 to stop): ");
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        if (num % 2 == 0)
        {
            appendToList(&head, num);
        }
        else
        {
            pushToList(&head, num);
        }
    }

    printf("Resulting list: ");
    printList(head);
}

/* 2- Add 100 randomly generated numbers to the list, write the c code that sorts all the
numbers entered from largest to smallest and prints them on the screen. */

extern void sortZeroToHundred()
{
    struct Node *head = NULL;
    int i;
    for (i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        appendToList(&head, num);
    }

    printf("Unsorted list: \n");
    printList(head);

    sortList(&head);

    printf("\n\nSorted list: \n");
    printList(head);
}

/* 3 - Write a function that stores the student number, name and age, traverses all the nodes in
the list, writes all the student information on the screen and counts it. */

extern void traverseStudentList()
{
    struct Student *head = NULL;

    addStudentToList(&head, 2100, "Eren", 20);
    addStudentToList(&head, 2101, "Selin", 21);
    addStudentToList(&head, 2102, "Eda", 22);

    printStudentList(head);
}

/* 4 - Write the function that searches records by student name in the list. */

extern boolean searchByNameInList()
{

    char searchName[50];
    printf("Enter the name you want to search for: ");
    scanf("%s", searchName);
    struct Student *head = NULL;
    struct Student *current = head;

    addStudentToList(&head, 2100, "Eren", 20);
    addStudentToList(&head, 2101, "Selin", 21);
    addStudentToList(&head, 2102, "Eda", 22);

    while (current != NULL)
    {
        printf("Current name: %s\n", current->name);
        if (strcmp(current->name, searchName) == 0)
        {
            printf("Student found - Student Number: %d, Name: %s, Age: %d\n", current->number, current->name, current->age);
            return true;
        }
        current = current->next;
    }
    printf("Student with the name %s not found.\n", searchName);
    return false;
}
