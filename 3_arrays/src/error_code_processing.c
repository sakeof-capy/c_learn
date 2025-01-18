#include <stdio.h>
#include <stddef.h>
#include "../include/array_utilities.h"

void error_code_processing(int* arr, int element, int* arr_size, int error_code)
{
    if (error_code == SUCCESS)
    {
        printf("Element %d deleted successfully!\n", element);
        if (*arr_size < 20)
        {
            printf("New array: \n");
            for (int i = 0; i < *arr_size; i++)
            {
                printf("%d ", arr[i]);
            }
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
}
