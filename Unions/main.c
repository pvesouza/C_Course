#include <stdio.h>
#include <stdlib.h>
#include <time.h>

union student_grade{
    char letterGrade;
    int roundedGrade;
    float exactGrade;
};

typedef union student_grade Grade;

int random(void);
void print_value(Grade grade);

int main()
{
    Grade variable1, variable2;
    variable1.roundedGrade = random();

    print_value(variable1);

    variable2.letterGrade = 'A';

    print_value(variable2);

    variable2.roundedGrade = random();

    print_value(variable2);

    variable2.exactGrade = 9.5;

    print_value(variable2);
    return 0;
}

int random() {
    srand(time(0));
    int number = rand() % 10;
    return number;
}

void print_value(Grade grade) {
    printf("Rounded Grade = %d\n", grade.roundedGrade);
    printf("Rounded Grade = %f\n", grade.exactGrade);
    printf("Rounded Grade = %c\n", grade.letterGrade);
    printf("The size of this union is %z\n", sizeof(grade));
    printf("-----------------------------------------------------------------\n");
}
