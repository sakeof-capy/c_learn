#ifndef ARRAY_UTITLITIES_H
#define ARRAY_UTITLITIES_H

extern const int ELEMENT_REMOVAL_SUCCESS;
extern const int ELEMENT_NOT_FOUND_ERROR;
extern const int NULL_POINTER_INPUT_ERROR;

int remove_first_ignore_order(int* arr, int* size, int target);
int remove_first_preserve_order(int* arr, int* size, int target);

#endif 
