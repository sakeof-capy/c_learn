#include <stdio.h>

/*
type* - non-const address(pointer) to non-const instance of type
const type* - non-const address(pointer) to const instance of type
type* const - const address(pointer) to non-const instance of type
const type* const - const address(poiner) to const instance of type
*/

void modify_integer(int* number)
{
    *number = 300;
}

void modify_integer_perfect_sample(int* const number)
{
    *number = 300;
}

int sum_elements(const int* array, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

int sum_elements_perfect_sample(const int* const array, int size)
{
    // array +=2; // leads to compile time error (assignment of read-only parameter 'array')
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

void array_elements_decrementor(int* const array, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        array[i] = array[i] - 1;
    }
}

/*
Homework on constants

1.  Create a separate pull request for these changes;
2.  Move this file to 1_basic_operations;
3.  Clean up this file: provide proper console output;
4.  Use size_t to represent array's size;
5.  Make sure you undertand everything about consts;
*/

int main()
{
    int number = 3;

    const int const_number = 3;

    number += 3;

    // const_number += 3; error: assignment of read-only variable 'const_number'

    printf("Before modification number = %d\n", number);

    modify_integer(&number);

    // modify_integer(&const_number); note: expected 'int *' but argument is of type 'const int *

    printf("After modification number = %d\n", number);

    printf("const_number = %d\n", const_number);

    int arr_size = 5;

    int array[] = {1, 19, 22, 66, -3};

    int array_sum = sum_elements(array, arr_size);

    printf("Sum of array elements: %d\n", array_sum);

    const int const_array[] = {1, 19, 22, 66, -3};
    
    int const_array_sum = sum_elements(const_array, arr_size); 
    // warning: passing argument 1 of 'sum_elements' discards 'const' qualifier from pointer target type

    printf("Sum of const array elements: %d\n", const_array_sum);

    return 0;
}