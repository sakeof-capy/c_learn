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
} PersonDate;

int validate_input(PersonDate* card)
{
    return 
    !(
        &(*card).date_of_birth.year < 1901 || 
        &(*card).date_of_birth.day > 31 || 
        &(*card).date_of_birth.month > 12 || 
        &(*card).date_of_birth.day < 1 || 
        &(*card).date_of_birth.month < 1
    ) || (
        &(*card).sex != 'M' && 
        &(*card).sex != 'F'
    );
}

int calculate_age(int birthYear) 
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int this_year = tm.tm_year + 1900;
    return this_year - birthYear;
}



int check_card(PersonDate card) 
{
    int birth = card.date_of_birth.year;
    int age = calculate_age(card.date_of_birth.year);
    char sex = card.sex;
    return validate_input(&card) && age >= 18 && age <= 55;
}

void feed_back(PersonDate card)
{
    int birth = card.date_of_birth.year;
    int age = calculate_age(card.date_of_birth.year);
    if (check_card(card))
    {
        printf("Sorry, not for you %d", age);
    } 
    else 
    {
        printf("Nice... Age is: %d", age);
    }
}

int can_engage_in_sexual_activity(PersonDate* card1, PersonDate* card2)
{
    int age_difference = &(*card1).date_of_birth.year - &(*card2).date_of_birth.year;
    return (age_difference < 30 || age_difference > -30) && &(*card1).sex != &(*card2).sex;
}

char to_uppercase(char letter) 
{
    if (letter == 'f')
    {
        return 'F';
    } 
    else if (letter == 'm')
    {
        return 'M';
    }
    else {
        return letter;
    } 
}

int main()
{
    int birthDay;
    int birthMonth;
    int birthYear;
    char sex;

    int studentBirthDay;
    int studentBirthMonth;
    int studentBirthYear;
    char studentSex;

    int teacherBirthDay;
    int teacherBirthMonth;
    int teacherBirthYear;
    char teacherSex;

    int hamaliyBirthDay;
    int hamaliyBirthMonth;
    int hamaliyBirthYear;
    char hamaliySex;
    
    printf("Yours sex (M if male and F if female) is ");
    scanf(" %c", &sex);

    printf("Year of birth is ");
    scanf("%d", &birthYear);

    printf("Day of birth is ");
    scanf("%d", &birthDay);

    printf("Month of birth is ");
    scanf("%d", &birthMonth);

    printf("Yours sex (M if male and F if female) is ");
    scanf(" %c", &studentSex);

    printf("Year of birth is ");
    scanf("%d", &studentBirthYear);

    printf("Day of birth is ");
    scanf("%d", &studentBirthDay);

    printf("Month of birth is ");
    scanf("%d", &studentBirthMonth);

    printf("Teachers sex (M if male and F if female) is ");
    scanf(" %c", &teacherSex);

    printf("Teachers year of birth is ");
    scanf("%d", &teacherBirthYear);

    printf("Teachers day of birth is ");
    scanf("%d", &teacherBirthDay);

    printf("Teachers month of birth is ");
    scanf("%d", &teacherBirthMonth);

    printf("Hamaliy sex (M if male and F if female) is ");
    scanf(" %c", &hamaliySex);

    printf("Hamaliy year of birth is ");
    scanf("%d", &hamaliyBirthYear);

    printf("Hamaliy day of birth is ");
    scanf("%d", &hamaliyBirthDay);

    printf("Hamaliy month of birth is ");
    scanf("%d", &hamaliyBirthMonth);

    PersonDate card = {
        .date_of_birth = {
            .day = birthDay, 
            .month = birthMonth, 
            .year = birthYear
        },
        .sex = to_uppercase(sex),
    };

    PersonDate studentCard = {
        .date_of_birth = {
            .day = studentBirthDay, 
            .month = studentBirthMonth, 
            .year = studentBirthYear
        },
        .sex = to_uppercase(studentSex),
    };

    PersonDate teacherCard = {
        .date_of_birth = {
            .day = teacherBirthDay, 
            .month = teacherBirthMonth, 
            .year = teacherBirthYear
        },
        .sex = to_uppercase(teacherSex),
    };

    PersonDate hamaliyCard = {
        .date_of_birth = {
            .day = hamaliyBirthDay, 
            .month = hamaliyBirthMonth, 
            .year = hamaliyBirthYear
        },
        .sex = to_uppercase(hamaliySex),
    };

    if (!validate_input(&card) || 
        !validate_input(&studentCard) ||
        !validate_input(&teacherCard) || 
        !validate_input(&hamaliyCard)) 
    {
        printf("invalid input: bad boy");
        return 1;
    }

    if (can_engage_in_sexual_activity(&card, &studentCard))
    {
        printf("I can fuck the student.\n");
    } 
    else
    {
        printf("The student is not for me.\n");
    }

    if (can_engage_in_sexual_activity(&card, &teacherCard))
    {
        printf("I can fuck the teacher.\n");
    } 
    else
    {
        printf("The teacher is not for me.\n");
    }

    if (can_engage_in_sexual_activity(&studentCard, &teacherCard))
    {
        printf("The student can fuck the teacher.\n");
    } 
    else
    {
        printf("The teacher is not for student.\n");
    }

    if (can_engage_in_sexual_activity(&teacherCard, &hamaliyCard))
    {
        printf("Hamaliy can fuck the teacher.\n");
    } 
    else
    {
        printf("The Hamaliy is not for teacher.\n");
    }

    return 0;
}

/*

Rename StudentCard => PersonCard;\n
Leave already implemented algorithm and extend it by 
    adding teacher_card object of type PersonCard
Ask user to input sex and date of birth for teacher 
Fill the teacher_card object
Likewise create and fill hamaliy object and implement the following functionality
After user inputs all the stuff print 3 conclusions: 
    1; You can have sex with student or not.
    2; Teacher can have sex with student or not.
    3; Hamaliy can have sex with teacher or not.
Two people can have sex under the same requirements.
Always print descriptive messages so that we can always understand who is fucking.
Pay special attencion to avoiding code duplication.

DONE

NEW HOMEWORK
    1. push current version of student_validator.c to getHam;
    2. copy the contents of the file to another file;
    3. modify the copy so that objects of structs are passed to functions via pointers;
    4. implement modifiers (setters) corresponding to all the implemented selectors (getters) in the almost_oop.c 
    5. ogo ti izvraschenets;




*/
