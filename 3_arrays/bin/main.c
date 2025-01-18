#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../include/array_utilities.h"
#include "../include/error_code_processing.h"

void sosibo_pederastia
(
    int* arr, 
    int* arr_size, 
    int element, 
    RemovalError (*array_element_remover) (int* , int* , int )
)
{
    int error_code;
    double elapsedTime;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    error_code = array_element_remover(arr, arr_size, element);
    gettimeofday(&end, NULL);
    error_code_processing(arr, element, arr_size, error_code);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("Execution time: %.6f seconds\n", elapsedTime);
}

void removal_benchmark
(
    int* arr, 
    int* arr_size,
    RemovalError (*array_element_remover) (int* , int* , int )
)
{
    sosibo_pederastia(arr, arr_size, arr[0], array_element_remover);
    sosibo_pederastia(arr, arr_size, arr[*arr_size/2], array_element_remover);
    sosibo_pederastia(arr, arr_size, arr[*arr_size-1], array_element_remover);
}

int main() 
{
    int arr_size;
    int error_code;
    int element;

    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    if (arr_size < 0)
    {
        printf("Invalid array size:(");
        return -1;
    }

    int *arr = (int *)malloc(arr_size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1; 
    }

    for (int i = 0; i < arr_size; i++) {
        arr[i] = i + 1;  
    }

    printf("remove_element_from_array: \n");
    removal_benchmark(arr, &arr_size, &remove_element_from_array);
    printf("\n");
    printf("remove_element_from_array_preserve_order: \n");
    removal_benchmark(arr, &arr_size, &remove_element_from_array_preserve_order);
    printf("\n");
    printf("remove_element_from_sorted_array_preserve_order: \n");
    removal_benchmark(arr, &arr_size, &remove_element_from_sorted_array_preserve_order);

    return 0;
}