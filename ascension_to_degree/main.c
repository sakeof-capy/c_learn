#include <stdio.h>

int ascens_to_degree(int number, int degree)
{
    int answer = number;
    if(degree == 1) 
    {
        return answer;
    } 
    else 
    {
        for (int i = 1; i < degree; i++)
        {
            answer = answer * number;
        }
    }
    return answer;
}

int main()
{
    int a;
    short int b;

    printf("Input number: ");
    scanf("%d", &a);

    printf("Input degree: ");
    scanf("%hu", &b);

    printf("Number = %d\n", a);
    printf("Degree = %hu\n", b);

    printf("%d^%d = %d", a, b, ascens_to_degree(a, b));

    return 0;
}