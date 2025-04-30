#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "../include/arrays/array_utilities.h"

int main()
{
    int arr[5] = {1, 10, 9, -3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int number;
    printf("SIZE: %d\n", sizeof(arr) / sizeof(arr[0]));

    printf("Enter your number: ");
    scanf("%d", &number);

    printf("Array: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int *dyn_arr; 
    int dyn_arr_size;  

    printf("Enter the number of elements of the dynamic array: ");
    scanf("%d", &dyn_arr_size);

    dyn_arr = (int *)malloc(dyn_arr_size * sizeof(int));

    printf("Enter %d integers:\n", dyn_arr_size);
    for (int i = 0; i < dyn_arr_size; i++) 
    {
        scanf("%d", &dyn_arr[i]);
    }

    printf("Dynamic array elements are: ");
    for (int i = 0; i < dyn_arr_size; i++) 
    {
        printf("%d ", dyn_arr[i]);
    }
    printf("\n");

   

    int error_code = remove_first_ignore_order(arr, &size, number);
    if (ELEMENT_REMOVAL_SUCCESS == 0)
    {
        printf("Array after removal: ");
        for (int i = 0; i < size; i++) 
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("Element %d not found in the array\n", number);
        printf("Array: ");
        for (int i = 0; i < size; i++) 
        {
            printf("%d ", arr[i]);
        }
    }

    remove_first_ignore_order(NULL, &size, number);

    arr[3];

    free(dyn_arr);
    //*(arr + 3) 

    // arr
    // Address of the first element

    // *arr
    // Value of the first element

    // arr[5] is value of the fifth element (the gay mode, the same ass *(arr+5))
    // arr + 5 is address of the fifth element
    // *(arr + 5) is value of the fifth element (chad mode, the same ass arr[5])
    
    // When static array is created, it is treated as array with a pointer to its first element.
    // Meaning sizeof(arr) / sizeof(arr[0]) returns its actual size.
    //But when the array is passed to a function, it loses its "array" component,
    //and starts behaving as a regular pointer.
    // Meaning sizeof(arr) / sizeof(arr[0]) starts returning 
    //(size of pointer) / sizeof(arr[0]) = 8 / sizeof(arr[0]) 
    //(for 64-bit)


    //dash
    // //hyphen

    // int *a, *b;
    // a = NULL;
    // b = NULL;

    return 0;
}

/*
Swap&cut

Instead of moving back all the trailing elements 
to cover the position of the removed element 
swap the removed element and the last element of the array 
and decrement the size of the array. DONE

Implement analogies to functions z remove an element from both static and dynamic arrays 
but assume that the array is sorted.

Understand what "extern" and "const" mean in C and get to know why we needed "extern"
for declaring the constants 
(error codes of remove_first_ignore_order() and remove_first_preserve_order() and find_index());

Rewrite the error codes of the functions so that they are organized as enum rather then as a set of constants



*/
