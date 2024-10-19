#include <stdio.h>

void set_one_to_variable(int* variable)
{
    printf("%p\n", variable);
    printf("%d\n", *variable);
    *variable = 1;
}

int main()
{
    int a = 0;
    set_one_to_variable(&a);
    printf("%d", a);
    return 0;
}