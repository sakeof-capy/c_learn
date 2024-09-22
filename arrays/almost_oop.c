#include <stdio.h>

typedef struct
{
    char sex;
    int age;
} Student;

int* get_age(Student* card)
{
    return &(*card).age;
}

char* get_sex(Student* card)
{
    return &(*card).sex;
}

int main()
{
    Student card = {
        .sex = 'a',
        .age = 17
    };

    int* a = get_age(&card);
    char* b = get_sex(&card);

    printf("%d\n", *a);
    printf("%c\n", *b);

    return 0;
}

//  Homework

//  Recap once again how get_age() is currently working;

//  Understand why do we need pointers here and what those pointers are pointing to;

//  Refactor get_sex() to match get_age() implementation;