#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void foo(int **ptr) {

    int a = 5;
    /* ptr is a local copy of the pointer and it has a
    different address from the original pointer*/
    *ptr = &a;
}

void foo1(char **ptr1) {
    *ptr1 = (char *)malloc(255 * sizeof(char));
    strcpy(*ptr1, "Hello World");
}

int main()
{
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("Address of a = %p\n", &a);
    printf("Address of p1 = %p\n", &p1);
    printf("Address of p2 = %p\n\n", &p2);

    printf("Value at the  address stored by p2 = %p\n", *p2);
    printf("Value at the  address stored by p1 = %d\n", *p1);
    printf("Value of **p2 = %d\n\n", **p2);

    int *ptr = NULL;
    ptr = (int *) malloc(sizeof(int));
    *ptr = 10;

    foo(&ptr);

    printf("%d\n", *ptr);

    char *ptrc = NULL;

    foo1(&ptrc);
    printf("%s\n", ptrc);

    free(ptrc);

    char familyNames[5][100] = {
    {"Pedro Victor"},
    {"Janaina Santos"},
    {"Lucca Pietro"},
    {"Joao Eduardo"},
    {"Aurora Pietra"},
    };

    for (int i = 0; i < 5; i++) {
        char *name = familyNames[i];
        printf("%s\n", name);
    }
    return 0;
}
