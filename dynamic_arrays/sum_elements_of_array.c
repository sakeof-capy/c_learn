#include <stdio.h>
#include "global.h"

int sum_elements_of_array(int array[], int size)
{
    int sum_of_array_elements = 1;
    for (int i = 0; i < size; i++)
    {
        sum_of_array_elements = sum_of_array_elements + array[i];
    }
    return sum_of_array_elements;
}