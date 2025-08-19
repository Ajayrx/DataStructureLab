/* Aim of the Experiment:
   Write a C Program using functions to perform the following operations on a
   single linked list: i) Creation, ii) Insertion, iii) Deletion, iv) Traversal
*/

#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

// Function to traverse the linked list
void traverse() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = start;
    while (temp != NULL) {
        printf("Data = %d\n", temp->info);
        temp = temp->next;
    }
}

// Function to insert at the front
void insertAtFront() {
    int data;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = start;
    start = temp;
}

// Function to insert at the end
void insertAtEnd() {
    int data;
    struct node *temp, *trav;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;
    if (start == NULL) {
        start = temp;
    } else {
        trav = start;
        while (trav->next != NULL)
            trav = trav->next;
        trav->next = temp;
    }
}

// Function to insert at any specified position
void insertAtPosition() {
    int data, pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);

    struct node *newnode = malloc(sizeof(struct node));
    newnode->info = data;

    if (pos == 1) {
        newnode->next = start;
        start = newnode;
        return;
    }

    struct node *temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\nPosition out of range\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete from the front
void deleteFirst() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

// Function to delete from the end
void deleteEnd() {
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    struct node *temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

// Function to delete from any specified position
void deletePosition() {
    int pos, i = 1;
    struct node *temp, *position;

    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        deleteFirst();
        return;
    }

    temp = start;
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    position = temp->next;
    temp->next = position->next;
    free(position);
}

// Driver Code
int main() {
    int choice;

    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To exit\n");
        printf("\nEnter Choice:\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1: traverse(); break;
        case 2: insertAtFront(); break;
        case 3: insertAtEnd(); break;
        case 4: insertAtPosition(); break;
        case 5: deleteFirst(); break;
        case 6: deleteEnd(); break;
        case 7: deletePosition(); break;
        case 8: exit(0);
        default: printf("Incorrect Choice. Try Again \n");
        }
    }
    return 0;
}
