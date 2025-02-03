#include <stdio.h>
#include <stddef.h>
#include "../include/strings_utilities.h"

void print_string(char *string, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        putchar(string[i]);
    }
}

int evaluate_null_terminated_string_size(char *string)
{
    int size = 0;
    for (int i = 0; ;i++)
    {
        if (string[i] == '\0')
        {
            break;
        } 
        else
        {
            size++;
        }
    }
    return size;
}

void print_null_terminated_string(char *string)
{
    int size = evaluate_null_terminated_string_size(string);
    print_string(string, size);
}

/////////////////////////////////////////////////////

void print_string_reversed(char* string)
{
    int size = evaluate_null_terminated_string_size(string);
    for (int i = size; i >= 0; i--)
    {
        putchar(string[i]);
    }
}

void revert_string(char* string)
{
    int size = evaluate_null_terminated_string_size(string);
    int left = 0, right = size - 1;
    while (left < right) 
    {
        char element = string[left];
        string[left] = string[right];
        string[right] = element;
        left++;
        right--;
    }
}

