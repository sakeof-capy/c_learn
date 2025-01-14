#include <stddef.h>
#include "../include/array_utilities.h"

RemovalError remove_element_from_array(int* arr, int* arr_size, int element)
{
    if (arr == NULL || arr_size == NULL)
    {
        return NULL_POINTER_ERROR;
    }
    int error_code = ELEMENT_NOT_FOUND;
    for(int i = 0; i < *arr_size; i++)
    {
        if (arr[i] == element)
        {
            arr[i] = arr[*arr_size-1];
            (*arr_size)--;
            error_code = SUCCESS;
            break;
        }
    }
    return error_code;
}