#include <stdio.h>
#include <time.h>
#include "../include/array_utilities.h"

int main() 
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int element = 10;

    // int error_code = remove_element_from_array(arr, &arr_size, element);
    // int error_code = remove_element_from_array_preserve_order(arr, &arr_size, element);
    // int error_code = remove_element_from_sorted_array(arr, &arr_size, element);
    int error_code = remove_element_from_sorted_array_preserve_order(arr, &arr_size, element);

    clock_t start = clock();
    int resultIterative = remove_element_from_sorted_array(arr, &arr_size, element);
    clock_t end = clock();
    double timeIterative = (double)(end - start) / CLOCKS_PER_SEC;

    if (error_code == SUCCESS)
    {
        printf("Element %d deleted successfully!\n", element);
        printf("New array: \n");
        for (int i = 0; i < arr_size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if (error_code == ELEMENT_NOT_FOUND)
    {
        printf("Element not found\n");
    }
    else if (error_code == NULL_POINTER_ERROR)
    {
        printf("NULL\n");
    }
    else 
    {
        printf("Unknown error happened\n");
    }

    printf("Iterative Result: %d, Time: %.6f seconds\n", resultIterative, timeIterative);

    return 0;
}