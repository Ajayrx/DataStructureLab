// Aim of the Experiment: Write a C program to perform Merge Sort.      
// - okay - upadted code 

#include <stdio.h>

void mergesort(int a[], int, int);
void merge(int[], int, int, int);

int main()
{
    int a[20], i, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, n - 1);

    printf("Data After Merge Sort: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}

void mergesort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);   
    }
}

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[20];

    while (i <= mid && j <= ub)   
    {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while (i <= mid)   
        b[k++] = a[i++];

    while (j <= ub)    
        b[k++] = a[j++];

    for (i = lb; i <= ub; i++)   
        a[i] = b[i];
}
