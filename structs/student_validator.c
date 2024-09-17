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
    char sex;
} StudentDate;

int calculate_age(int birthYear) 
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int this_year = tm.tm_year + 1900;
    return this_year - birthYear;
}

int checkCard(StudentDate card) 
{
    int birth = card.date_of_birth.year;
    int age = calculate_age(card.date_of_birth.year);
    char sex = card.sex;

    return birth < 1901 || age < 18 || age > 50 || sex == 'M' || sex == 'm';
}

StudentDate feedBack(StudentDate card)
{
    int birth = card.date_of_birth.year;
    int age =  calculate_age(card.date_of_birth.year);
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
    

    int birthDay;
    int birthMonth;
    int birthYear;
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
    };

    if (birthYear < 1901 || birthDay > 31 || birthMonth > 12 || birthDay < 1 || birthMonth < 1)
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
