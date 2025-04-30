#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[5] = {1, 10, 9, -3, 5};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Array: ");
    for(int i = 0; i < arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, arrSize, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}