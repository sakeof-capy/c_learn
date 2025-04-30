#include <stddef.h>
#include "../../include/arrays/array_utilities.h"

const int ELEMENT_REMOVAL_SUCCESS = 0;
const int ELEMENT_NOT_FOUND_ERROR = -1;
const int NULL_POINTER_INPUT_ERROR = -2;

int find_index(int* arr, int size, int target) 
{
    for (int i = 0; i < size; i++) 
    {
        if (arr[i] == target) 
        {
            return i; 
        }
    }
    return ELEMENT_NOT_FOUND_ERROR; 
}

int remove_first_ignore_order(int* arr, int* size, int target)
{
    if (size == NULL || arr == NULL)
    {
      return NULL_POINTER_INPUT_ERROR;
    }
    int index = find_index(arr, *size, target);
    if (index == ELEMENT_NOT_FOUND_ERROR) 
    {
        return ELEMENT_NOT_FOUND_ERROR;
    }
    int a = arr[*size - 1];
    arr[*size - 1] = arr[index];
    arr[index] = a;
    (*size)--;

    return ELEMENT_REMOVAL_SUCCESS;
}

int remove_first_preserve_order(int* arr, int* size, int target)
{
    if (size == NULL || arr == NULL)
    {
      return NULL_POINTER_INPUT_ERROR;
    }
    int index = find_index(arr, *size, target);
    if (index == ELEMENT_NOT_FOUND_ERROR) 
    {
        return ELEMENT_NOT_FOUND_ERROR;
    }
    for (int i = index; i < *size - 1; i++) 
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;

    return ELEMENT_REMOVAL_SUCCESS;
}