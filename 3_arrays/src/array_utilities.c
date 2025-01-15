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

//  1.  Implement function `remove_element_from_array_preserve_order` 
//      z would preserve the order of array's elements after removal.

RemovalError remove_element_from_array_preserve_order(int* arr, int* arr_size, int element)
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
            for (int y = i; y < *arr_size - 1; y++) 
            {
                arr[y] = arr[y + 1];
            }
            (*arr_size)--;
            error_code = SUCCESS;
            break;
        }
    }
    return error_code;
}

//  2.  Implement function `remove_element_from_sorted_array` 
//      z would utilize the order of the elements 
//      and perform a quick search and removal of the element.

RemovalError remove_element_from_sorted_array(int* arr, int* arr_size, int element) 
{
    int error_code = ELEMENT_NOT_FOUND;
    int low = 0, high = *arr_size - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == element) 
        {
            arr[mid] = arr[*arr_size-1];
            (*arr_size)--;
            error_code = SUCCESS;
            break;
        } 
        else if (arr[mid] < element) 
        {
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1; 
        }
    }
    return error_code;
}

//  3.  Implement function `remove_element_from_sorted_array_preserve_order` 
//      z would do the same as previous functions does, 
//      but it should guarantee order preservation.

RemovalError remove_element_from_sorted_array_preserve_order(int* arr, int* arr_size, int element) 
{
    int error_code = ELEMENT_NOT_FOUND;
    int low = 0, high = *arr_size - 1;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == element) 
        {
            for (int y = mid; y < *arr_size - 1; y++) 
            {
                arr[y] = arr[y + 1];
            }
            (*arr_size)--;
            error_code = SUCCESS;
            break;
        } 
        else if (arr[mid] < element) 
        {
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1; 
        }
    }
    return error_code;
}
