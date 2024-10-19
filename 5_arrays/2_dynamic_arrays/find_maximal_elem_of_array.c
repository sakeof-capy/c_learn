#include <stdio.h>
#include "global.h"

int find_maximal_elem_of_array(int array[], int size)
{
    int maximal_elem_of_array = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > maximal_elem_of_array)
        {
            maximal_elem_of_array = array[i];
        }
    }
    return maximal_elem_of_array;
}