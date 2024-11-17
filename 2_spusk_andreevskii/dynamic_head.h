#ifndef DYNAMIC_ARRAYS_H
#define DYNAMIC_ARRAYS_H

typedef struct {
    int number;
    int verdict;
} Result;

Result find_specific_integer_of_array(int array[], int size,  int spec_num);

Result sum_elements_of_array(int array[], int size);

Result find_minimal_elem_of_array(int array[], int size);

Result find_maximal_elem_of_array(int array[], int size);

int reverse_array_of_integers(int array[], int size);

#endif
