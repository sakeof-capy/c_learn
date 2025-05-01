#include "array_utils.h"
#include <stddef.h>

SumErrorCode sum_array(int* array, int size, int* output)
{
    if (size <= 0) 
    {
        return INVALID_ARRAY_LENGTH;
    }

    if (array == NULL)
    {
        return NULL_ARRAY_POINTER;
    }

    if (output == NULL)
    {
        return NULL_OUTPUT_POINTER;
    }

    int result = 0;

    for (int i = 0; i < size; ++i) 
    {
        result += array[i];
    }

    *output = result;

    return SUCCESS;
}
