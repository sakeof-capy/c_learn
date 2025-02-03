#include <stdio.h>
#include "../include/strings_utilities.h"

int main()
{
    char new_string[] = "abrakadabra";
    char string_to_revert[] = "abbra";

    // char symbol = 's';
    // printf("%c\n", symbol);

    char myString[] = {'s', 't', 'r', 'i', 'n', 'g', '\n', '\0'};
    printf("%d\n", myString);
    printf("%d\n", myString[4]); // myString[4] == *(myString + 4)
    printf("%d\n", *myString); // myString[0] == *(myString + 0)

    int arr_size = sizeof(myString) / sizeof(myString[0]);
    printf("%d\n", arr_size);

    print_string(myString, arr_size);

    int size = evaluate_null_terminated_string_size(myString);

    printf("%d\n", size);

    print_null_terminated_string(myString);

    char empty_string[] = {'\0'};

    print_null_terminated_string(empty_string);

    print_null_terminated_string(new_string);
    printf("\n");

    //////////////////////////////////////////////

    print_string_reversed(string_to_revert);
    printf("\n");

    revert_string(string_to_revert);
    printf("%s\n", string_to_revert);

    return 0;
}