// Aim of The Experiment-: To find the largest element in a given doubly linked list.
// oaky 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A structure of Doubly linked list node */

struct node
{

    int data;
    struct node *prev, *next;
}*head;


void initialize()
{

    head = NULL;
}

// Given a Inserts a node in front of a doubly linked list.

void insert(int num)
{

    // Create a new Linked List node

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = num;

    // Insert newNode before head node

    newNode->next = head;

    newNode->prev = NULL;

    if (head != NULL)
    {

        head->prev = newNode;
    }
    /* Set newNode as head of doubly linked list */

    head = newNode;

    printf("Inserted Element: %d\n", num);
}

int getMaxNode(struct node *head)
{

    /* Input Validation */

    if (head == NULL)
    {

        printf("Error: Invalid Input !!!!\n");

        return INT_MIN;
    }

    int max = head->data;

    while (head != NULL)
    {

        if (head->data > max)
        {

            max = head->data;
        }
        head = head->next;
    }
    return max;
}

/*Prints a linked list from head node till tail node */

void printLinkedList(struct node *nodePtr)
{

    printf("Doubly Linked List\n");

    while (nodePtr != NULL)
    {
        printf("%d", nodePtr->data);

        nodePtr = nodePtr->next;

        if (nodePtr != NULL)

            printf("-><-");
    }
}

int main()
{
    initialize();

    /* Insert elements in Doubly linked list */

    insert(4);

    insert(9);

    insert(12);

    insert(1);

    /* print Doubly Linked list */

    printLinkedList(head);

    /* Printing maximum value node*/

    printf("\n Maximum Value in Linked List: %d", getMaxNode(head));

    return 0;
}