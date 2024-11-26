#include <stdio.h>
#include "array_utils.h"

typedef enum 
{
    READ_SINGLE_NUMBER_SUCCESS,
    NULLPTR_DESTINATION,
    INVALID_COUNT_OF_READ_ELEMENTS,
} ReadSingleNumberErrorCode;

ReadSingleNumberErrorCode read_single_number(int* destination)
{
    if (destination == NULL)
    {
        return NULLPTR_DESTINATION;
    }

    int read_items_count = scanf("%d", destination);

    if (read_items_count != 1)
    {
        return INVALID_COUNT_OF_READ_ELEMENTS;
    }

    return READ_SINGLE_NUMBER_SUCCESS;
}

int main() 
{
    int n;
    ReadSingleNumberErrorCode read_result;
    const int MAX_ARRAY_SIZE = 50;

    printf("Enter the number of elements: ");
    read_result = read_single_number(&n);

    if (read_result != READ_SINGLE_NUMBER_SUCCESS)
    {
        printf("ERROR: invalid input");
        return read_result;
    }

    if (n <= 0 || n > MAX_ARRAY_SIZE)
    {
        printf(
            "ERROR: number of elements %d is out of bounds of the allowed range: 1..%d.", 
            n, 
            MAX_ARRAY_SIZE
        );
        return -1;
    }

    int arr[n]; 

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) 
    {
        printf("Element %d: ", i + 1);
        read_result = read_single_number(&arr[i]);

        if (read_result != SUCCESS)
        {
            printf("ERROR: invalid input");
            return read_result;
        }
    }

    printf("You entered: ");

    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    int sum;
    const SumErrorCode error_code = sum_array(arr, n, &sum);

    if (error_code != SUCCESS)
    {
        printf("The program run hit an error");
        return error_code;
    }

    printf("Sum of the array: %d", sum);

    return 0;
}
