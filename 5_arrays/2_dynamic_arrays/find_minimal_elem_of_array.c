#include <stdio.h>
#include "global.h"

int find_minimal_elem_of_array(int array[], int size)
{
    int minimal_elem_of_array = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] < minimal_elem_of_array)
        {
            minimal_elem_of_array = array[i];
        }
    }
    return minimal_elem_of_array;
}