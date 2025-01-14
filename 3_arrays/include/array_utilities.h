#ifndef ARRAY_UTILITIES_H_
#define ARRAY_UTILITIES_H_

typedef enum 
{
    SUCCESS,
    ELEMENT_NOT_FOUND,
    NULL_POINTER_ERROR
} RemovalError;

RemovalError remove_element_from_array(int* arr, int* arr_size, int element);

#endif
