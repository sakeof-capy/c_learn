#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

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
   
    int myArray[] = {1, 2, 10, 3, 44, 45, 17, 7, 4};
    int arraySize = sizeof(myArray) / sizeof(myArray[0]);
    int number = 0;
    int findingResult; 

    qsort(myArray, arraySize, sizeof(int), compare);

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

    printf("The function took %.50f seconds to execute.\n", elapsed_time);

    return 0;
}

