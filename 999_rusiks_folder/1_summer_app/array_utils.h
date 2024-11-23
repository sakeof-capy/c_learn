#ifndef ARRAY_UTILS_H_
#define ARRAY_UTILS_H_

typedef enum
{
    SUCCESS,
    INVALID_ARRAY_LENGTH,
    NULL_ARRAY_POINTER,
    NULL_OUTPUT_POINTER,
} SumErrorCode; 

SumErrorCode sum_array(int* array, int size, int* output);

#endif 
