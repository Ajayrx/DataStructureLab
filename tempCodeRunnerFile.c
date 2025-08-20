/*Aim of the Experiment: (a) Write a C Program using functions to perform the following operations on a
single linked list: i) Creation, ii) Insertion, iii) Deletion, iv) Traversal */

#include <stdio.h>
#include <stdlib.h>

// Linked List Node

struct node
{
    int info;
    struct node *prev, *next;
};

struct node *start = NULL;

// Function to traverse the linked list

void traverse()

{

    // List is empty

    if (start == NULL)
    {
        printf("\nList is empty\n");
        return;
    }

    // Else print the Data

    struct node *temp;
    temp = start;

    while (temp != NULL)
    {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

// Function to insert at the front of the linked list

void insertAtFront()

{
    int data;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;

    // Pointer of temp will be assigned to start

    temp->next = start;
    start = temp;
}

// Function to insert at the end of the linked list

void insertAtEnd()

{
    int data;
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;
    trav = start;

    // If start is NULL

    if (start == NULL)
    {
        start = temp;
    }

    else
    {

        while (trav->next != NULL)

            trav = trav->next;

        temp->prev = trav;

        trav->next = temp;
    }
}

// Function to insert at any specified position in the linked list

void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;

    // Enter the position and data

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (start == NULL)
    {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
    else if (pos == 1)
    {
        insertAtFront();
    }

    else
    {
        printf("\nEnter number to be inserted: ");
        scanf("%d", &data);
        newnode->info = data;
        temp = start;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
}

// Function to delete from the front of the linked list

void deleteFirst()
{

    struct node *temp;
    if (start == NULL)
        printf("\nList is empty\n");

    else
    {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
}

// Function to delete from the end of the linked list

// Function to delete from the end of the linked list
void deleteEnd()
{
    struct node *temp;

    if (start == NULL)
    {
        printf("\nList is empty\n");
        return; // FIX: exit early
    }

    temp = start;

    // If only one node
    if (start->next == NULL)
    {
        free(start); // FIX: free the only node
        start = NULL;
        return;
    }

    // Move to last node
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

// Function to delete from any specified position from the linked list
void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;

    if (start == NULL)
    {
        printf("\nList is empty\n");
        return; // FIX: exit early
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    // If the position is the first node
    if (pos == 1)
    {
        deleteFirst();
        return; // FIX: don't free again
    }

    // Traverse till position-1 or end
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("\nPosition out of range\n"); // FIX: safeguard
        return;
    }

    position = temp->next;
    temp->next = position->next;

    if (position->next != NULL)
        position->next->prev = temp;

    free(position);
}


// Driver Code

int main()
{
    int choice;

    while (1)
    {

        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at"
               " starting\n");
        printf("\t3 For insertion at"
               " end\n");
        printf("\t4 For insertion at "
               "any position\n");
        printf("\t5 For deletion of "
               "first element\n");
        printf("\t6 For deletion of "
               "last element\n");
        printf("\t7 For deletion of "
               "element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            traverse();
            break;

        case 2:

            insertAtFront();
            break;

        case 3:

            insertAtEnd();
            break;

        case 4:

            insertAtPosition();
            break;

        case 5:

            deleteFirst();
            break;

        case 6:

            deleteEnd();
            break;

        case 7:

            deletePosition();
            break;

        case 8:

            exit(1);
            break;

        default:

            printf("Incorrect Choice. Try Again \n");
            continue;
        }
    }
    return 0;
}
