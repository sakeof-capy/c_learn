#include <stdio.h>
#include <stddef.h>
#include "../include/array_utilities.h"
#include "../include/array_structure.h"

void error_code_processing(ArrayStructure* array, int element, int error_code)
{
    if (error_code == SUCCESS)
    {
        if ((*array).arr_size < 20)
        {
            printf("New array: ");
            for (int i = 0; i < (*array).arr_size; i++)
            {
                printf("%d ", (*array).arr[i]);
            }
            printf("\n");
        }
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
