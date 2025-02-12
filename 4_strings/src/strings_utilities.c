#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../include/strings_utilities.h"

void print_string(const char* string, const size_t arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        putchar(string[i]); 
    }
}

int evaluate_null_terminated_string_size(const char* string)
{
    size_t size = sizeof(string) / sizeof(string[0]);
    while (string[size-1] == '\0')
    {
        return size;
    } 
    size++;
}

void print_null_terminated_string(const char *string)
{
    const size_t arr_size = strlen(string);
    for (int i = 0; i < arr_size; i++)
    {
        putchar(string[i]); 
    }
}

void print_string_reversed(const char* string)
{
    const size_t arr_size = strlen(string);
    for (int i = arr_size; i >= 0; i--)
    {
        putchar(string[i]);
    }
}

void revert_string(char* string)
{
    char* left = string;
    char* right = string;
    char element = *string;

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



