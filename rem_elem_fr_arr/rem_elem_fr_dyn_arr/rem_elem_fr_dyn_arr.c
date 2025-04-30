#include <stdio.h>
#include <stdlib.h>

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

    // printf("%d", found);

    if (found != 1) {
        printf("Element %d not found in the array.\n", element);
        return;
    }

    // printf("%d", i);

    for (int delInd = i; delInd < *size - 1; delInd++) {
        arr[delInd] = arr[delInd + 1];
    }

    (*size)--;

    printf("Element %d deleted successfully.\n", element);
}

int main() {
    int arrSize; 
    int element;

    printf("Enter the size of the array: ");
    scanf("%d", &arrSize);

    int *array = (int *)malloc(arrSize * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    printf("Enter %d elements:\n", arrSize);
    for (int i = 0; i < arrSize; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The elements of the array are:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    qsort(array, arrSize, sizeof(int), compare);

    printf("Sorted array: ");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("Enter the element to delete: ");
    scanf("%d", &element);

    deleteElement(array, &arrSize, element);

    printf("Array after deletion:\n");
    for (int i = 0; i < arrSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}