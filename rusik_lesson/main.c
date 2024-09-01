#include <stdio.h>

int main () 
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

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i + 1; ++j) 
        {
            printf("*");
        }

        if (i != n - 1) 
        {
            printf("\n");
        }
    }

    return 0;
};
