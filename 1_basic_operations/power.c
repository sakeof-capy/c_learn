#include <stdio.h>

// int ascens_to_power(int number, int power)
// {
//     int answer = number;
//     if(power == 1) 
//     {
//         return answer;
//     } 
//     else if (power == 0 || power == 1)
//     {
//         return answer = 1;
//     } 
//     else
//     {
//         for (int i = 1; i < power; i++)
//         {
//             answer = answer * number;
//         }
//         return answer;
//     }
// }

int power(int number, unsigned int power)
{
    int answer = 1;
    for (int i = 0; i < power; ++i)
    {
        answer *= number;
    }
    return answer;
}

int main()
{
    int a;
    unsigned int b;

    printf("Input number: ");
    scanf("%d", &a);

    printf("Input power: ");
    scanf("%u", &b);

    printf("Number = %d\n", a);
    printf("power = %u\n", b);

    printf("%d^%u = %d", a, b, power(a, b));

    return 0;
}