#include <stdio.h>
#include "global.h"

int reverse_array_of_integers(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", array[i]);
    }
}