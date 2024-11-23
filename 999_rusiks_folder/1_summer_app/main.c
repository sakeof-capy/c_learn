#include <stdio.h>
#include "array_utils.h"

int main() 
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; 

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("You entered: ");

    for (int i = 0; i < n; i++) {
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
