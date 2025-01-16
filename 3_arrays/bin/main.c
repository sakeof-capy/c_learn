#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/array_utilities.h"
#include "../include/error_code_processing.h"

int main() 
{
    struct timeval start, end;
    double elapsedTime;

    int arr_size;
    int error_code;
    int element;

    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int *arr = (int *)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = i + 1;  
    }

    printf("Enter element for deletion: ");
    scanf("%d", &element);
    error_code = remove_element_from_array(arr, &arr_size, element);
    gettimeofday(&start, NULL);
    error_code_processing(arr, element, &arr_size, error_code);
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("Execution time: %.6f seconds\n", elapsedTime);

    printf("Enter element for deletion: ");
    scanf("%d", &element);
    error_code = remove_element_from_array_preserve_order(arr, &arr_size, element);
    gettimeofday(&start, NULL);
    error_code_processing(arr, element, &arr_size, error_code);
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("Execution time: %.6f seconds\n", elapsedTime);

    printf("Enter element for deletion: ");
    scanf("%d", &element);
    error_code = remove_element_from_sorted_array_preserve_order(arr, &arr_size, element);
    gettimeofday(&start, NULL);
    error_code_processing(arr, element, &arr_size, error_code);
    gettimeofday(&end, NULL);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("Execution time: %.6f seconds\n", elapsedTime);

    return 0;
}