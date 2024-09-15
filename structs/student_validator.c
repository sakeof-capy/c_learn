#include<stdio.h>

typedef struct 
{
    int age;
    int birth;
    char name[10];
} StudentDate;

int checkCard(StudentDate card) 
{
    int age = card.age;
    int birth = card.birth;

    return age < 18 || birth > 1991;
}

StudentDate feedBack(StudentDate card)
{
    int age = card.age;
    int birth = card.birth;

    if(checkCard(card))
    {
        printf("is not for you");
    } else {
        printf("Nice");
    }
}

int main()
{
    int getAge;
    int getBirthDay;
    char getName[10];
    
    scanf("%d", &getAge);
    scanf("%d", &getBirthDay);
    scanf("%s", &getName);

    StudentDate card = {.age = getAge, .birth = getBirthDay};

    feedBack(card);
    
    return 0;
}