#include <stdio.h>
#include <stddef.h>
#include "../include/strings_utilities.h"

void print_string(char* string, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        putchar(string[i]); 
    }
}

int evaluate_null_terminated_string_size(const char* string)
{
    size_t size = 0;
    for (int i = 0; ;i++)
    {
        while (string[i] == '\0')
        {
            return size;
        } 
        size++;
    }
}

void print_null_terminated_string(char *string)
{
    size_t size = evaluate_null_terminated_string_size(string);
    print_string(string, size);
}

void print_string_reversed(const char* string)
{
    size_t size = evaluate_null_terminated_string_size(string);
    for (int i = size; i >= 0; i--)
    {
        putchar(string[i]);
    }
}

void revert_string(char* string)
{
    char* left = string;
    char* right = string;
    char element;

    while (*right != '\0')
    {
        right++;
    }

    right--;

    while (left < right) 
    {
        element = *left;
        *left = *right;
        *right = element;
        left++;
        right--;
    }
}



