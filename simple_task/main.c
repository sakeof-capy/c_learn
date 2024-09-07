#include <stdio.h>

void printStars(int count) 
{
    for (int i = 0; i < count; ++i)
    {
        printf("*");
    }
}

int main() 
{
    int a;

    scanf("%d", &a);

    printf("%d\n", a);

    /*
        i = 5
        *****
        ****
        *** 
        **
        *
    */

   for (int i = 0; i < a; ++i)
   {
        printStars(a - i);
        printf("\n");
   }


    return 0;
}