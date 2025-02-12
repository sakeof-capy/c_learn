#include <stdio.h>
#include "../include/strings_utilities.h"

int main()
{
    char simple_string[] = "abrakadabra";
    char string_to_revert[] = "ytrewq";
    char manually_filled_char_array[] = {'s', 't', 'r', 'i', 'n', 'g', '\n', '\0'};
    char empty_string[] = {'\0'};
    const char* const_string = " gnirts_tsnoc";

    printf("print_null_terminated_string(string): ");
    print_null_terminated_string(simple_string);
    printf("\n");
    
    printf("printf manually_filled_char_array:    %d\n", manually_filled_char_array);
    printf("printf manually_filled_char_array[4]: %d\n", manually_filled_char_array[4]); // myString[4] == *(myString + 4)
    printf("printf *manually_filled_char_array:   %d\n", *manually_filled_char_array); // myString[0] == *(myString + 0)

    const int arr_size = sizeof(manually_filled_char_array) / sizeof(manually_filled_char_array[0]);
    printf("printf sizeof(manually_filled_char_array): %d\n", arr_size);

    printf("print_string(manually_filled_char_array, arr_size): ");
    print_string(manually_filled_char_array, arr_size);

    int size = evaluate_null_terminated_string_size(manually_filled_char_array);
    printf("evaluate_null_terminated_string_size(manually_filled_char_array): ");
    printf("%d\n", size);

    printf("print_null_terminated_string(manually_filled_char_array): ");
    print_null_terminated_string(manually_filled_char_array);

    printf("print_null_terminated_string(empty_string): ");
    print_null_terminated_string(empty_string);
    printf("\n");

    printf("print_string_reversed(string_to_revert): ");
    print_string_reversed(string_to_revert);
    printf("\n");

    printf("print_string_reversed(const_string): ");
    print_string_reversed(const_string);
    printf("\n");

    revert_string(string_to_revert);
    printf("Reverted string: %s\n", string_to_revert);
    
    return 0;
}