#ifndef ARRAY_UTILITIES_H_
#define ARRAY_UTILITIES_H_

typedef enum 
{
    SUCCESS,
    ELEMENT_NOT_FOUND,
    NULL_POINTER_ERROR
} RemovalError;

RemovalError binary(int* arr, size_t* arr_size, int element);
RemovalError remove_element_from_array(int* arr, size_t* arr_size, int element);
RemovalError remove_element_from_array_preserve_order(int* arr, size_t* arr_size, int element);
RemovalError remove_element_from_sorted_array(int* arr, size_t* arr_size, int element);
RemovalError remove_element_from_sorted_array_preserve_order(int* arr, size_t* arr_size, int element);

#endif
