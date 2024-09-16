#include <stdio.h>
#include <time.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct 
{
    Date date_of_birth;
    int age;
    char sex;

} StudentDate;

int checkCard(StudentDate card) 
{
    int birth = card.date_of_birth.year;
    int age = card.age;
    char sex = card.sex;

    return birth < 1901 || age < 18 || age > 50 || sex == 'M' || sex == 'm';
}

StudentDate feedBack(StudentDate card)
{
    int birth = card.date_of_birth.year;
    int age = card.age;
    if (checkCard(card))
    {
        printf("Sorry, not for you %d", age);
    } 
    else 
    {
        printf("Nice... \nAge is: %d", age);
    }
}

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("now: %d\n", tm.tm_year + 1900);

    int birthDay;
    int birthMonth;
    int birthYear;
    int age;
    char sex;

    printf("\nYours sex (M if male and F if female) is ");
    scanf("%c", &sex);

    printf("\nDay of birth is ");
    scanf("%d", &birthDay);

    printf("\nMonth of birth is ");
    scanf("%d", &birthMonth);

    printf("\nYear of birth is ");
    scanf("%d", &birthYear);

    StudentDate card = {
        .date_of_birth = {
            .day = birthDay, 
            .month = birthMonth, 
            .year = birthYear
        },
        .sex = sex,
        .age = tm.tm_year + 1900 - birthYear
    };

    if (birthYear < 1901 || birthDay > 31 || birthMonth > 12)
    {
        printf("Invalid date");
    }
    else if(sex == 'm' || sex == 'M' || sex == 'f' || sex == 'F')
    {
        feedBack(card);
    } 
    else
    {
        printf("Invalid gender");
    }

    return 0;
}
/*

1. Add gender to structure StudentCard; gender can have 2 valid values ("male", "female");

2. If gender is not valid print "invalid gender";

3. If gender is valid form a verdict based on age and gender;

4. If input date is valid print calculated age and verdict;

5. If input date is not valid print "invalid date";

*/