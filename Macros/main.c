#include <stdio.h>
#include <stdlib.h>

//Defines a Macro that sums two parameters

#define SUM(x,y) (x + y)

#define SQUARE(x) (x*x)

#define CUBE(x) (x*x*x)

#define IS_UPPER(ch)  ((ch >= 'A' && ch <= 'Z') ? 1 : 0)

#define IS_LOWER(ch) ((ch >= 'a' && ch <= 'z') ? 1 : 0)

#define NUMERIC(ch) ((ch >= '0' && ch <= '9') ? 1 : 0)

int main()
{

    printf("The line is %d\n", __LINE__);
    printf("File name %s\n", __FILE__);
    printf("Last compilation date %s\n", __DATE__);
    printf("Time of the last compilation: %s\n",__TIME__);

    if (__STDC__ == 1) {
        printf("The compiler supports standard C\n");
    }
    else {
         printf("The does not compiler supports standard C\n");
    }

    printf("Type 2 numbers\n");

    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    // Input two numbers by the user
    scanf("%d\n%d", &n1, &n2);
    fflush(stdin);
    // Calculates the sum of the two numbers
    printf("The sum is %d\n", SUM(n1,n2));

    printf("Type another number to calculate the square and cube\n");
    fflush(stdin);
    scanf("%d", &n3);


    printf("The square of %d is %d\n",n3, SQUARE(n3));
    printf("The cube pf %d is %d\n",n3, CUBE(n3));

    printf("Type a character from a to z lower or upper case\n");
    char c = '\0';
    fflush(stdin);
    c = getchar();

    if (IS_UPPER(c)){
        printf("Type a character %c is upper", c);
    }
    else if (IS_LOWER(c)) {
        printf("Type a character %c is lower", c);
    }
    else if (NUMERIC(c)){
        printf("Type a character %c is numeric", c);
    }
    else {
         printf("Type a character %c is especial", c);
    }

    return 0;
}
