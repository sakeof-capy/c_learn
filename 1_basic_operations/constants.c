#include <stdio.h>
#include <stdlib.h>
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

int sum_elements(const int* array, const size_t arr_size)
{
    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum = sum + array[i];
    }
    const int const_sum = sum;
    return const_sum;
}

int sum_elements_perfect_sample(const int* const array, const size_t arr_size)
{
    // array +=2; // leads to compile time error (assignment of read-only parameter 'array')
    int sum = 0;
    for (int i = 0; i < arr_size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

void array_elements_decrementor(int* const array, const size_t arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        array[i+=1]; 
    }
}

int main()
{
    int number = 3;

    const int const_number = 3;

    const size_t arr_size = 5;

    int array[] = {1, 19, 22, 66, -3};

    const int const_array[] = {1, 19, 22, 66, -3};

    number += 3;

    // const_number += 3; error: assignment of read-only variable 'const_number'

    printf("Integer number before modification = %d\n", number);

    modify_integer(&number);

    // modify_integer(&const_number); note: expected 'int *' but argument is of type 'const int *

    printf("Integer number after modification = %d\n", number);

    printf("const_number = %d\n", const_number);

    const int array_sum = sum_elements(const_array, arr_size);

    printf("Sum of array elements: %d\n", array_sum);

    // warning: passing argument 1 of 'sum_elements' discards 'const' qualifier from pointer target type
    const int const_array_sum = sum_elements(const_array, arr_size); 

    printf("Sum of const array elements: %d\n", const_array_sum);

    const size_t big_array_size = 2500000000;

    int* const big_array = (int*)malloc(big_array_size * sizeof(int));

    if (big_array == NULL) 
    {
        printf("Not enough memory");
        return -1;
    }

    const size_t BIG_INDEX = 2147483647;

    for (size_t j = 0; j < BIG_INDEX; j++) 
    {
        big_array[j] = 1;
    }

    big_array[BIG_INDEX + 10] = 100;

    const int big_sum = sum_elements_perfect_sample(big_array, big_array_size);

    printf("big_sum = %d", big_sum);

    return 0;
}