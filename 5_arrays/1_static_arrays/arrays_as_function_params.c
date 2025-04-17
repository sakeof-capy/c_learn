#include <stdio.h>

//Print the sum of elements of this array

int sum_elements_of_array(int array[], int size)
{
    int sum_of_array_elements = 1;
    for (int i = 0; i < size; i++)
    {
        sum_of_array_elements = sum_of_array_elements + array[i];
    }
    return sum_of_array_elements;
}

//Find the minimal element of the array and print it

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

//Find the maximal element of the array and print it

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

//Find and print the reverse of the array

int reverse_array_of_integers(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
}

int main()
{
    //Create an array of ints with 10 elements and print all it's elements

    static int integers_array[] = {11, 8, 89, 4, 5, 6, 7, 8, 9, 10};

    int size = sizeof(integers_array) / sizeof(integers_array[0]);

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