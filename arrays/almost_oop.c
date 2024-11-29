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

void set_age(Student* card, int age)
{
    if (age > 0 && age < 120)
    {
        card->age = age;    
    } 
    else 
    {
        printf("Invalid age provided.\n");
    }
}

char* get_sex(Student* card)
{
    return &(*card).sex;
}

void set_sex(Student* card, char sex)
{
    card->sex = sex;
}

int main()
{
    Student card = {
        .sex = 'f',
        .age = 17
    };

    int* a = get_age(&card);
    char* b = get_sex(&card);

    set_age(&card, 33);
    set_sex(&card, 'm');

    printf("%d\n", *a);
    printf("%c\n", *b);

    return 0;
}

//  Homework

//  Recap once again how get_age() is currently working;

//  Understand why do we need pointers here and what those pointers are pointing to;

//  Refactor get_sex() to match get_age() implementation;