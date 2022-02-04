#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

long unsigned int factorial(int n);                // Calculates the factorial of a number recursively
int read_input(void);                // Reads the input and returns the integer number with more than one digit
int exponential(int n);
void up_and_down(int n);
void print(int n);

int main()
{
    int number = read_input();
    printf("Factorial of %d is %ld\n", number, factorial(number));

    up_and_down(1);

    print(10);

    return 0;
}

long unsigned int factorial(int n) {

    if (n == 0){
        return 1;
    }
    long int result = n * factorial(n - 1);
    printf("n = %d and fact = %ld\n", n, result);
    return result;
}

int exponential(int n) {
    if (n == 0)
        return 1;

    int base10  = 10;
    for (int i = 1; i < n; i++){
        base10 = base10 * 10;
    }

    return base10;
}

int read_input(void) {

    int sum = 0;
    int ch = '\0';
    int exp = 0;

    // Allocates memory to stores the digits
    int *pt_digits = malloc(1 * sizeof(int));

    do{
        ch = getchar();
        int number =  ch - 48;

        if (number >= 0){
           pt_digits[exp] = number;
           exp ++;
           realloc(pt_digits, 1 * sizeof(int));
        }

    }while(ch != 10);

    for (int i = 0; i < exp; i++) {

        sum = pt_digits[i] * exponential(exp - (i + 1)) + sum;
    }

    return sum;

}

void up_and_down(int n) {

    printf("Level %d: n location %p\n", n &n);

    if (n < 4) {
        up_and_down(n + 1);
    }

    printf("LEVEL %d: n location %p\n", n &n);
}

void print(int n) {

    if (n < 0) {
        return;
    }
    print(n - 1);
    printf("%d\n", n);
}
