#ifndef STRINGS_UTILITIES_H_
#define STRINGS_UTILITIES_H_

void print_string(const char* const string, const size_t arr_size);
size_t evaluate_null_terminated_string_size(const char* string);
void print_null_terminated_string(const char *string);
void print_string_reversed(const char* string);
void revert_string(char* string);

#endif