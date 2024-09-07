#include <stdio.h>

int main() 
{
    int a;

    scanf("%d", &a);

    printf("%d\n", a);

    /*
    *
    **
    ***
    ****
    *****
    */

    for (int i = 0; i < a; i++) 
    {
        for (int o = a - i; o <= a; ++o) 
        {
            printf("*");
        }
              
        if (i != a - 1)
        {
            printf("\n");
        }
    }

    return 0;
}