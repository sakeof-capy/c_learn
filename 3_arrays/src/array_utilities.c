#include <stdlib.h>
#include <stddef.h>
#include "../include/array_utilities.h"

int find_index_of(int* arr, size_t* arr_size, int element)
{
    int found_index;
    for(int i = 0; i < *arr_size; i++)
    {
        if (arr[i] == element)
        {
            found_index = i;
        }
    }
    return found_index;
}

void shift_elements_of_array_to_left(int* arr, size_t* arr_size, int index)
{
    for (int new_index = index; new_index < *arr_size - 1; new_index++) 
    {
        arr[new_index] = arr[new_index + 1];
    }
}

RemovalError remove_element_from_array(int* arr, size_t* arr_size, int element)
{
    if (arr == NULL || arr_size == NULL)
    {
        return NULL_POINTER_ERROR;
    }
    int found_index = -1;
    found_index = find_index_of(arr, arr_size, element);
    if (found_index == -1)
    {
        return ELEMENT_NOT_FOUND;
    }
    arr[found_index] = arr[*arr_size -1];
    (*arr_size)--;
    return SUCCESS;
}

// factor out as the separate fuction the for loop searching for index 
// name it index_of.
// use it in first two functions to find the index of the wanted element 
// then use this index either for swapping or shifting elements backward

//  1.  Implement function `remove_element_from_array_preserve_order` 
//      z would preserve the order of array's elements after removal.

RemovalError remove_element_from_array_preserve_order(int* arr, size_t* arr_size, int element)
{
    if (arr == NULL || arr_size == NULL)
    {
        return NULL_POINTER_ERROR;
    }
    int found_index = -1;
    found_index = find_index_of(arr, arr_size, element);
    if (found_index == -1)
    {
        return ELEMENT_NOT_FOUND;
    }
    shift_elements_of_array_to_left(arr, arr_size, found_index);
    (*arr_size)--;
    return SUCCESS;
}

//  2.  Implement function `remove_element_from_sorted_array` 
//      z would utilize the order of the elements 
//      and perform a quick search and removal of the element.

int find_index_binary_search(int* arr, size_t* arr_size, int element)
{
    int low = 0, high = *arr_size - 1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2; 
        if (arr[mid] == element) 
        {
            return mid;
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
    return -1;
}

RemovalError remove_element_from_sorted_array(int* arr, size_t* arr_size, int element) 
{
    int found_index = find_index_binary_search(arr, arr_size, element);
    if (found_index != -1)
    {
        arr[found_index] = arr[*arr_size -1];
        (*arr_size)--;
        return SUCCESS;
    }
    return ELEMENT_NOT_FOUND;
}

//  3.  Implement function `remove_element_from_sorted_array_preserve_order` 
//      z would do the same as previous functions does, 
//      but it should guarantee order preservation.

RemovalError remove_element_from_sorted_array_preserve_order(int* arr, size_t* arr_size, int element) 
{
    int found_index= find_index_binary_search(arr, arr_size, element);
    if (found_index != -1)
    {
        shift_elements_of_array_to_left(arr, arr_size, found_index);
        (*arr_size)--;
        return SUCCESS;
    }
    return ELEMENT_NOT_FOUND;
;
}
