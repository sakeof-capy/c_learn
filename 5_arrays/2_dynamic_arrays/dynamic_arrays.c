#include <stdio.h>
#include <stdlib.h>
#include "global.h"

int sum_elements_of_array();

int find_minimal_elem_of_array();

int find_maximal_elem_of_array();

int reverse_array_of_integers();

int reverse_array_of_integers();

int main()
{

    printf("Enter number of integers: \n", size);
    scanf("%d", &size);

    integers_array = (int *)malloc(size * sizeof(int));

    printf("Enter %d integers: \n", size);
    for (int i = 0; i < size; i++) {
    scanf("%d", &integers_array[i]);
    }

    printf("sum_elements_of_array %d\n", sum_elements_of_array(integers_array, size));

    printf("minimal_elem_of_array: %d\n", find_minimal_elem_of_array(integers_array, size));

    printf("maximal_elem_of_array: %d\n", find_maximal_elem_of_array(integers_array, size));

    reverse_array_of_integers(integers_array, size);

    return 0;
}