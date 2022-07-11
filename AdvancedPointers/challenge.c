#include<stdio.h>

int sum(const int* arr1, const int* arr2, int size);
int multi(const int* arr1, const int* arr2, int size);
int sub(const int* arr1, const int* arr2, int size);
int div(const int* arr1, const int* arr2, int size);



int main(void) 
{
    // Stop character
    char c = '\0';
    int **d = &*d;
    // Reads a character from stdin
    
    const int arr1[] = {20, 30, 40, 50, 60};
    const int arr2[] = {2, 3, 4, 5, 6};

    typedef int(*operation)(const int*, const int*, int);

    operation pt;

    while(c != '5')
    {
        printf("Type the operation:\n\n");
        printf("1 - Sum\n");
        printf("2 - Subtraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Division\n");
        printf("5 - None\n\n\n\n");

        c = getc(stdin);

        printf("Character: %c\n", c);

        switch (c)
        {
        case '1':
            printf("Teste1 %d\n\n", c);
            pt = sum;
            break;
        case '2':
            printf("Teste2 %d\n\n", c);
            pt = sub;
            break;
        case '3':
            printf("Teste3 %d\n\n", c);
            pt = multi;
            break;

        case '4':
            printf("Teste4 %d\n\n", c);
            pt = div;
            break;
        
        default:
            break;
        }

        (*pt)(arr1, arr2, 5);
        __fpurge(stdin);
    }

    printf("The program ended\n");
}

int sum(const int* arr1, const int* arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        int sum = arr1[i] + arr2[i];
        if (i == 0)
        {
             printf("Result = [");
        }
        if (i != size - 1)
        {
            printf("%d, ", sum);
        }else{
            printf("%d ]\n", sum);
        }
    }
}
int multi(const int* arr1, const int* arr2, int size)
{
     for (int i = 0; i < size; i++)
    {
        int sum = arr1[i] * arr2[i];
        if (i == 0)
        {
             printf("Result = [");
        }
        if (i != size - 1)
        {
            printf("%d, ", sum);
        }else{
            printf("%d ]\n", sum);
        }
    }
}
int sub(const int* arr1, const int* arr2, int size)
{
     for (int i = 0; i < size; i++)
    {
        int sum = arr1[i] - arr2[i];
        if (i == 0)
        {
             printf("Result = [");
        }
        if (i != size - 1)
        {
            printf("%d, ", sum);
        }else{
            printf("%d ]\n", sum);
        }
    }
}
int div(const int* arr1, const int* arr2, int size)
{
     for (int i = 0; i < size; i++)
    {   
        int sum = 0;
        if (arr2[i] != 0) 
        {
            sum = arr1[i] / arr2[i];
        }else{
            sum = 0;
        }
        if (i == 0)
        {
            printf("Result = [");
        }
        if (i != size - 1)
        {
            printf("%d, ", sum);
        }else{
            printf("%d ]\n", sum);
        }
        
    }
}


