#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "../include/strings_utilities.h"

void print_string(const char* const string, const size_t arr_size)
{
    for (size_t i = 0; i < arr_size; i++)
    {
        putchar(string[i]); 
    }
}

size_t evaluate_null_terminated_string_size(const char* const string)
{
    // size_t size = 0;
    // for (; string[size] != '\0'; size++);
    // return size - 1;

    //or (better)

    size_t size = 0;
    while (string[size] != '\0')
    {
        size++;
    }
    return size;
}

void print_null_terminated_string(const char* const string)
{
    const size_t arr_size = evaluate_null_terminated_string_size(string);
    for (size_t i = 0; i < arr_size; i++)
    {
        putchar(string[i]); 
    }
}

void print_string_reversed(const char* const string)
{
    const size_t arr_size = evaluate_null_terminated_string_size(string);
    for (size_t i = 0; i < arr_size; i++)
    {
        putchar(string[arr_size - i -1]);
    }
}

void revert_string(char* const string)
{
    const size_t size = evaluate_null_terminated_string_size(string);
    char* left = string;
    char* right = left + size - 1;
    char element = *string;

    while (left < right) 
    {
        element = *left;
        *left = *right;
        *right = element;
        left++;
        right--;
    }
}



