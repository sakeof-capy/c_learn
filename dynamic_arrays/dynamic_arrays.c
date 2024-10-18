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
    //Create an array of ints with 10 elements and print all it's elements

    printf("Enter number of integers: \n", size);
    scanf("%d", &size);

    integers_array = (int *)malloc(size * sizeof(int));

    printf("Enter %d integers: \n", size);
    for (int i = 0; i < size; i++) {
    scanf("%d", &integers_array[i]);
    }

    //Print the sum of elements of this array

    printf("sum_elements_of_array %d\n", sum_elements_of_array(integers_array, size));

    //Find the minimal element of the array and print it

    printf("minimal_elem_of_array: %d\n", find_minimal_elem_of_array(integers_array, size));

    //Find the maximal element of the array and print it

    printf("maximal_elem_of_array: %d\n", find_maximal_elem_of_array(integers_array, size));

    //Find and print the reverse of the array

    reverse_array_of_integers(integers_array, size);

    return 0;
}