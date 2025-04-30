#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 

int compare(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

void deleteElement(int arr[], int *size, int element) {
    int i, found = 0;

    for (i = 0; i < *size; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", element);
        return;
    }

    for (int delInd = i; delInd < *size - 1; delInd++) {
        arr[delInd] = arr[delInd + 1];
    }

    (*size)--;

    printf("Element %d deleted successfully.\n", element);
}

int main() {
    int arr[MAX_SIZE]; 
    int arrSize;
    int element;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &arrSize);

    if (arrSize <= 0 || arrSize > MAX_SIZE) {
        printf("Invalid size! Please enter a number between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The elements of the array are:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    qsort(arr, arrSize, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to delete: ");
    scanf("%d", &element);

    deleteElement(arr, &arrSize, element);

    printf("Array after deletion:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}