#include <stdio.h>
#include <stdlib.h>
#include "dynamic_head.h"

void users_integers_answer(int verdict, int number, const char *mes) 
{
    if (verdict == 0)
    {
        printf("%s: %d\n", mes, number);
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
    int specific_integer;
    char my_mes[] = "number";

    printf("Enter number of integers: \n", size);
    scanf("%d", &size);

    integers_array = (int *)malloc(size * sizeof(int));

    printf("Enter %d integers: \n", size);

    for (int i = 0; i < size; i++) 
    {
    scanf("%d", &integers_array[i]);
    }

    printf("What integer you wanna find?\n");
    scanf("%d", &specific_integer);

    Result result_find = find_specific_integer_of_array(integers_array, size, specific_integer);
    users_integers_answer(result_find.verdict, result_find.number, my_mes);

    Result result_sum = sum_elements_of_array(integers_array, size);
    users_integers_answer(result_sum.verdict, result_sum.number, my_mes);

    Result result_min = find_minimal_elem_of_array(integers_array, size);
    users_integers_answer(result_min.verdict, result_min.number, my_mes);

    Result result_max = find_maximal_elem_of_array(integers_array, size);
    users_integers_answer(result_max.verdict, result_max.number, my_mes);
    
    reverse_array_of_integers(integers_array, size);

    free(integers_array);

    return 0;
}