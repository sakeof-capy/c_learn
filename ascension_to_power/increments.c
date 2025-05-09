#include <stdio.h>

int print_int(int integer)
{
    printf("%d", integer);
}

int main()
{
    int a1 = 10;
    int a2 = 10;
    int b = ++a1;
    int c = a2++;

    printf("a1 = %d\na2 = %d\nb = %d\nc = %d\n", a1, a2, b, c);

    for (int i = 0; i < 10; ++i)
    {
        printf("%d", i);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d", i);
    }

    int gogi = 13;

    printf("\n");
    print_int(gogi++);
    printf("\n");
    print_int(++gogi);
    printf("\n");
    print_int(gogi);

    return 0;
}