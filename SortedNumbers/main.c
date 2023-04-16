#include <stdio.h>
#include <stdlib.h>

#include "sortedLib.c"

#define LENGHT 100

int comparador(const void *v1, const void *v2);

int main()
{
    double arr[LENGHT];
    // Fill in the array
    fill_array_double(arr, LENGHT);
    show_array_double(arr, LENGHT);

    qsort(arr, LENGHT, sizeof(double), comparador);
    show_array_double(arr, LENGHT);

    return 0;
}

int comparador(const void *v1, const void *v2) {

    // Dereferencing the values
    double value1 = *(double*)v1;
    double value2 = *(double*)v2;

    if (value1 > value2) {
        return 1;
    }else if (value1 < value2) {
        return -1;
    }else {
        return 0;
    }
}
