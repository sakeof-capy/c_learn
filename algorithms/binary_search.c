#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;  // Return the index if found
        } else if (arr[mid] < target) {
            low = mid + 1;  // Narrow to the right half
        } else {
            high = mid - 1;  // Narrow to the left half
        }
    }
    return -1;  // Return -1 if the number is not found
}

int findNumber(int *myArray, int arraySize, int number) {
    for (int i = 0; i < arraySize; i++) {
        if (myArray[i] == number) {
            return number; 
        }
    }
    return -1; 
}

int main() {
    clock_t start_time, end_time;
    double elapsed_time;

    int arraySize = 1000000000;
    
    int* myArray = (int*)malloc(sizeof(int)*arraySize);

    int number = 0;
    int findingResult; 

    for (int i = 0; i < arraySize; i++)
    {
        myArray[i] = i + 1;
    }
    

    qsort(myArray, arraySize, sizeof(int), compare);

    printf("Enter your number: ");
    scanf("%d", &number);

    printf("Regular search: \n");

    start_time = clock();

    findingResult = findNumber(myArray, arraySize, number);

    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The function took %.15f seconds to execute.\n", elapsed_time);

    printf("Binary search: \n");

    start_time = clock();

    findingResult = binarySearch(myArray, arraySize, number);

    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The function took %.15f seconds to execute.\n", elapsed_time);
    
    if (findingResult != -1) {
        printf("Number %d found at index %d.\n", number, findingResult);
    } else {
        printf("Number %d not found in the array.\n", number);
    }

    return 0;
}