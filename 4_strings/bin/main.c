#include <stdio.h>

// void print_string(char string[], int arr_size)
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

int main()
{
    printf("Hello, arrays!\n");

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

    // "abrakadabra"

    char new_string[] = "abrakadabra";

    print_null_terminated_string(new_string);

    return 0;
}