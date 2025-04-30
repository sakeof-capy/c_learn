#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../include/search/search.h"

void print_result(int result) 
{
    if (result == -1)
    {
        printf("Sorry, your number is not in array.\n");
    }
    else
    {
        printf("Yep: %d\n", result);
    }
}

int measure_and_print_time(
    int* array, 
    int array_size, 
    int number, 
    int (*search_function)(
        int*, 
        int, 
        int
        )
)
{
    LARGE_INTEGER frequency, start, end;
    double elapsed_ns;
    int findingResult; 

    if (QueryPerformanceFrequency(&frequency) == 0) {
        printf("High-resolution counter not supported.\n");
        return 1;
    }

    QueryPerformanceCounter(&start);
    findingResult = search_function(array, array_size, number);
    QueryPerformanceCounter(&end);

    print_result(findingResult);

    elapsed_ns = (double)(end.QuadPart - start.QuadPart) * 1e9 / frequency.QuadPart;
    printf("Elapsed time: %.0f nanoseconds\n", elapsed_ns);
    return 0;
}

int main()
{
    int arraySize = 10000000;
    int* myArray = (int*)malloc(sizeof(int) * arraySize);
    int number = 0;

    for (int i = 0; i < arraySize; i++)
    {
        myArray[i] = i + 1;
    }

    printf("Enter your number: ");
    scanf("%d", &number);

    measure_and_print_time(myArray, arraySize, number, &findNumber);
    measure_and_print_time(myArray, arraySize, number, &binarySearch);

    return 0;
}

// int main() {
//     clock_t start_time, end_time;
//     double elapsed_time;

//     int arraySize = 1000000000;
    
//     int* myArray = (int*)malloc(sizeof(int)*arraySize);

//     int number = 0;
//     int findingResult; 

//     for (int i = 0; i < arraySize; i++)
//     {
//         myArray[i] = i + 1;
//     }
    
//     qsort(myArray, arraySize, sizeof(int), compare);

//     printf("Enter your number: ");
//     scanf("%d", &number);

//     printf("Regular search: \n");

//     start_time = clock();

//     findingResult = findNumber(myArray, arraySize, number);

//     end_time = clock();

//     elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

//     printf("The function took %.15f seconds to execute.\n", elapsed_time);

//     printf("Binary search: \n");

//     start_time = clock();

//     findingResult = binarySearch(myArray, arraySize, number);

//     end_time = clock();

//     elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

//     printf("The function took %.15f seconds to execute.\n", elapsed_time);
    
//     if (findingResult != -1) {
//         printf("Number %d found at index %d.\n", number, findingResult);
//     } else {
//         printf("Number %d not found in the array.\n", number);
//     }

//     return 0;
// }

