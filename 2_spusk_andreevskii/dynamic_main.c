#include <stdio.h>
#include <stdlib.h>
#include "dynamic_head.h"

int users_integers_answer(int verdict, int number) 
{
    if (verdict == 0)
    {
        printf("number: %d\n", number);
    }
    else
    {
        printf("error\n");
    }
}

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

    Result result_sum = sum_elements_of_array(integers_array, size);

    users_integers_answer(result_sum.verdict, result_sum.number);

    Result result_min = find_minimal_elem_of_array(integers_array, size);

    users_integers_answer(result_min.verdict, result_min.number);

    Result result_max = find_maximal_elem_of_array(integers_array, size);

    users_integers_answer(result_max.verdict, result_max.number);
    
    reverse_array_of_integers(integers_array, size);

    free(integers_array);

    return 0;
}