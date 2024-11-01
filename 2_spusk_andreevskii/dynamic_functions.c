#include <stdio.h>

int sum_elements_of_array(int array[], int size)
{
    if (size > 0)
    {
        int sum_of_array_elements = 0;
        for (int i = 0; i < size; i++)
        {
            sum_of_array_elements = sum_of_array_elements + array[i];
        }
        return 0 && sum_of_array_elements; 
    }
    else
    {
        return 1;
    }
    
    
}

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
        return (minimal_elem_of_array);
}

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

int reverse_array_of_integers(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
}