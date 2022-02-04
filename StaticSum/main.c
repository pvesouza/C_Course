#include <stdio.h>
#include <stdlib.h>

int sum(int);

int main()
{
    printf("Sum = %d", sum(10));
    printf("Sum = %d", sum(20));
    printf("Sum = %d", sum(30));
    return 0;
}

int sum(int n){
    static int result = 0;
    result = result + n;
    return result;
}
