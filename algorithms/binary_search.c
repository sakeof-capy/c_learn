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

int main() {
    clock_t start_time, end_time;
    double elapsed_time;

    int myArray[] = {1, 2, 10, 3, 44, 45, 17, 7, 4};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    int number = 0;
    int findingResult; 

    qsort(myArray, arraySize, sizeof(int), compare);

    printf("Enter your number: ");
    scanf("%d", &number);

    start_time = clock();

    findingResult = binarySearch(myArray, arraySize, number);

    end_time = clock();

    findingResult = binarySearch(myArray, arraySize, number);

    if (findingResult != -1) {
        printf("Number %d found at index %d.\n", number, findingResult);
    } else {
        printf("Number %d not found in the array.\n", number);
    }

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The function took %.50f seconds to execute.\n", elapsed_time);

    return 0;
}