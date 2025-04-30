#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int grade = 0;
    printf("Enter your grade: ");
    scanf("%d", &grade);

    if (grade >= 60)
    {
        printf("Congratulations!");
    }
    else
    {
        printf("Fail. Try again.");
    }
    
    return 0;
}