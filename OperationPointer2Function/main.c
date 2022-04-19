#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// Arrays to operation
int arraya[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int arrayb[] = {38, 27, 87, 63, 59, 223, 132, 1, 19, 7};

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mul(int a, int b) {return a * b;}
int division(int a, int b) {return (a / b);}

typedef int operationFunction(int, int);

void *operateArrays(int *array1, int *array2, int **out, int size, operationFunction *op) {

    *out = (int*) malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        int value = (*op)(array1[i], array2[i]);
        *(*out + i) = value;
        //printf("%d  ", value);
    }

    return *out;
}

void printResults(int **results, int size) {

    for (int i = 0; i < size; i++) {
        printf("%d  ", *(*results + i));
    }
    printf("\n");
    free(*results);
}


int main()
{
    int number = 0;
    // Pointer to function
    operationFunction *op;

    do {
        printf("Type on operation\n");
        printf("1 - SUM\n");
        printf("2 - SUB\n");
        printf("3 - MULTIPLICATION\n");
        printf("4 - DIVISION\n");
        printf("5 - QUIT\n");

        scanf("%d", &number);

        switch(number) {
            case 1:
                op = add;
                break;
            case 2:
                op = sub;
                break;
            case 3:
                op = mul;
                break;
            case 4:
                op = division;
                break;
        }

        if (number != 5) {
            int *results = NULL;
            operateArrays(arraya, arrayb, &results, 10,op);
            printResults(&results, 10);
        }
    }while(number != 5);
    return 0;
}
