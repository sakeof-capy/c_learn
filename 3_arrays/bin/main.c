#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>
#include "../include/array_utilities.h"
#include "../include/error_code_processing.h"

void measure_time
(
    int* arr, 
    size_t* arr_size, 
    int element, 
    RemovalError (*array_element_remover) (int* , size_t* , int ),
    const char* message
)
{
    int error_code;
    double elapsedTime;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    error_code = array_element_remover(arr, arr_size, element);
    gettimeofday(&end, NULL);
    error_code_processing(arr, arr_size, error_code);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("%s %.6f seconds\n", message, elapsedTime);
}

void removal_benchmark
(
    int* arr, 
    size_t* arr_size,
    RemovalError (*array_element_remover) (int* , size_t* , int )
)
{
    measure_time(arr, arr_size, arr[*arr_size/2], array_element_remover, "- Removing element from beggining:");
    measure_time(arr, arr_size, arr[*arr_size-1], array_element_remover, "- Removing element from middle:   ");
    measure_time(arr, arr_size, arr[0], array_element_remover,           "- Removing element from end:      ");
}

int main() 
{
    size_t arr_size = 0;

    printf("Enter the size of the array: ");
    scanf("%zu", &arr_size);

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

    for (size_t i = 0; i < arr_size; i++) {
        arr[i] = i + 1;  
    }

    printf("\n");
    printf("remove_element_from_array_preserve_order: ");
    printf("\n");
    removal_benchmark(arr, &arr_size, &remove_element_from_array_preserve_order);

    printf("remove_element_from_sorted_array_preserve_order: ");
    printf("\n");
    removal_benchmark(arr, &arr_size, &remove_element_from_sorted_array_preserve_order);

    printf("remove_element_from_sorted_array: ");
    printf("\n");
    removal_benchmark(arr, &arr_size, &remove_element_from_sorted_array);

    printf("remove_element_from_array: ");
    printf("\n");
    removal_benchmark(arr, &arr_size, &remove_element_from_array);

    return 0;
}