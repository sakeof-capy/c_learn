#include <stdio.h>
#include "../include/array_utilities.h"

int main() 
{
    int arr[] = {1, 2, 3, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int element = 1;

    int error_code = remove_element_from_array(arr, &arr_size, element);

    if (error_code == SUCCESS)
    {
        printf("Element %d deleted successfully!\n", element);
        printf("New array: \n");
        for (int i = 0; i < arr_size; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if (error_code == ELEMENT_NOT_FOUND)
    {
        printf("Element not found\n");
    }
    else if (error_code == NULL_POINTER_ERROR)
    {
        printf("NULL\n");
    }
    else 
    {
        printf("Unknown error happened\n");
    }

    printf("SUCCESS = %d\n", SUCCESS);
    printf("SUCCESS = %d\n", ELEMENT_NOT_FOUND);
    printf("SUCCESS = %d\n", NULL_POINTER_ERROR);

    
    return 0;
}