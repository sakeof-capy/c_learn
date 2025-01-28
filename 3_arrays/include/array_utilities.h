#ifndef ARRAY_UTILITIES_H_
#define ARRAY_UTILITIES_H_
#include "array_structure.h"

typedef enum 
{
    SUCCESS,
    ELEMENT_NOT_FOUND,
    NULL_POINTER_ERROR
} RemovalError;

RemovalError remove_element_from_array(ArrayStructure* array1, int element);
RemovalError remove_element_from_array_preserve_order(ArrayStructure* array2, int element);
RemovalError remove_element_from_sorted_array(ArrayStructure* array3, int element);
RemovalError remove_element_from_sorted_array_preserve_order(ArrayStructure* array4, int element);

// void func_acceptor(RemovalError(*function)(ArrayStructure*, int))
// {
//     ArrayStructure* arr = NULL;
//     int to_found = 3;
//     RemovalError error_code = function(arr, to_found);
//     if (error_code != SUCCESS)
//     {
//         printf("Fuck you, asshole.");
//     }
// }

#endif
