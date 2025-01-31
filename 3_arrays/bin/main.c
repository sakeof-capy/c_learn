#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/time.h>
#include "../include/array_utilities.h"
#include "../include/error_code_processing.h"
#include "../include/array_structure.h"

void measure_time
(
    ArrayStructure* array,
    int element, 
    RemovalError(*array_element_remover)(ArrayStructure*, int),
    const char* message
)
{
    int error_code;
    double elapsedTime;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    error_code = array_element_remover(array, element);
    gettimeofday(&end, NULL);
    error_code_processing(array, element, error_code);
    elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("%s %.6f seconds\n", message, elapsedTime);
}

void removal_benchmark
(
    ArrayStructure* array,
    RemovalError(*array_element_remover)(ArrayStructure*, int)
)
{
    measure_time(array, (*array).arr[(*array).arr_size/2], array_element_remover, "- Removing element from beggining:");
    measure_time(array, (*array).arr[(*array).arr_size-1], array_element_remover, "- Removing element from middle:   ");
    measure_time(array, (*array).arr[0], array_element_remover,           "- Removing element from end:      ");
}

int main() 
{
    size_t arr_size = 0;
    int element;

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

    ArrayStructure array = {
        .arr = arr,
        .arr_size = arr_size,
    };

    for (int i = 0; i < array.arr_size; i++) {
        array.arr[i] = i + 1;  
    }

    printf("\n");
    printf("remove_element_from_array_preserve_order: ");
    printf("\n");
    removal_benchmark(&array, &remove_element_from_array_preserve_order);

    printf("remove_element_from_sorted_array_preserve_order: ");
    printf("\n");
    removal_benchmark(&array, &remove_element_from_sorted_array_preserve_order);

    printf("remove_element_from_sorted_array: ");
    printf("\n");
    removal_benchmark(&array, &remove_element_from_sorted_array);

    printf("remove_element_from_array: ");
    printf("\n");
    removal_benchmark(&array, &remove_element_from_array);

    return 0;
}