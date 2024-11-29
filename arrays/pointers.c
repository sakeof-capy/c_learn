#include <stdio.h>

void set_value_to_variable(int value, int* variable)
{
    *variable = value;
}

void swap(int* first_variable, int* second_variable)
{

    int temporary_value = *first_variable;
    *first_variable = *second_variable;
    *second_variable = temporary_value;
}

int main()
{
    int serduck = 5;
    set_value_to_variable(3, &serduck);
    printf("%d\n", serduck);

    int alpha = 1;
    int beta = 2;

    swap(&alpha, &beta);

    printf("First %d\n", alpha);
    printf("Second %d\n", beta);

    return 0;
}