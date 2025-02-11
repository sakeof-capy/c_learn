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

    return 0;
}