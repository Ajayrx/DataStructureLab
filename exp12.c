// Aim of the Experiment: Write a C program to implement Linear Search.
// okay 

#include <stdio.h>

int main()
{

    int arr[20], size, key, i, index;
    printf("Number of elements in the list: ");
    scanf("%d", &size);

    printf("Enter elements of the list: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search ie. key element: ");
    scanf("%d", &key);

    for (index = 0; index < size; index++)
        if (arr[index] == key) // comparing each element with the key element break;

            if (index < size)
                printf("Key element found at index %d", index); // printing the index if key found
            else
                printf("Key element not found");

    return 0;
}