#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/search/search.h"

int binarySearch(int* arr, int size, int target) {
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
