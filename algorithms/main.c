#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findNumber(int *myArray, int arraySize, int number) {
    for (int i = 0; i < arraySize; i++) {
        if (myArray[i] == number) {
            return number; 
        }
    }
    return -1; 
}

int main()
{
    clock_t start_time, end_time;
    double elapsed_time;

    int arraySize = 100000000;
   
    int* myArray = (int*)malloc(sizeof(int) * arraySize);
    int number = 0;
    int findingResult; 

    for (int i = 0; i < arraySize; i++)
    {
        myArray[i] = i + 1;
    }

    printf("Enter your number: ");
    scanf("%d", &number);

    start_time = clock();

    findingResult = findNumber(myArray, arraySize, number);
    findNumber(myArray, arraySize, number);

    end_time = clock();

    if (findingResult == -1)
    {
        printf("Sorry, your number is not in array.\n");
    }
    else
    {
        printf("Yep: %d\n", findingResult);
    }

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("The function took %.15f seconds to execute.\n", elapsed_time);

    return 0;
}

