#include <stdio.h>
#include <stdlib.h>

#include "data.h"



int main()
{

    MyArray *ptr;

    printf("Choose the size of the array\n");
    int tempSize;
    scanf("%d", &tempSize);

    ptr = (MyArray*)malloc(sizeof(MyArray) + tempSize * sizeof(int));
    ptr->lenght = tempSize;

    printf("%d\n", ptr->lenght);

    for (int i = 0; i < ptr->lenght; i++){
        ptr->array[i] = i + 2;
    }

    for (int i = 0; i < ptr->lenght; i++){
         printf("%d\n", ptr->array[i]);
    }

    return 0;
}
