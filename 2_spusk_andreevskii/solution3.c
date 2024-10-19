#include <stdio.h>

void put_stars(int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("*");
    }
}

int main() 
{
    // Console input: n 
    // n = 5 : 
    // *            i = 0 -> i + 1 of '*'
    // **           i = 1 -> i + 1 of '*'
    // ***          i = 2 -> i + 1 of '*'
    // ****         i = 3 -> i + 1 of '*'
    // *****        i = 4 -> i + 1 of '*'

    int n;

    printf("Input n: ", n);
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        put_stars(i);
        if (i < n) 
        {
            printf("\n");
        }
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     printf("\n");
    // }

    return 0;
};
