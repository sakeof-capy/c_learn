#include <stdio.h>
#include <stdlib.h>
#include "dynamic_head.h"

int main()
{
    int *integers_array;
    int size;

    printf("Enter number of integers: \n", size);
    scanf("%d", &size);

    integers_array = (int *)malloc(size * sizeof(int));

    printf("Enter %d integers: \n", size);

    for (int i = 0; i < size; i++) 
    {
    scanf("%d", &integers_array[i]);
    }

    printf("sum_elements_of_array %d\n", sum_elements_of_array(integers_array, size));

    printf("minimal_elem_of_array: %d\n", find_minimal_elem_of_array(integers_array, size));

    printf("maximal_elem_of_array: %d\n", find_maximal_elem_of_array(integers_array, size));

    reverse_array_of_integers(integers_array, size);

    free(integers_array);

    return 0;
}