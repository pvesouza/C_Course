#include <stdio.h>
#include <time.h>

void fill_array_double(double *arr, int lenght) {
    int i = 0;
    srand(time(NULL));

    for (i = 0; i < lenght; ++i) {
        arr[i] = ( (double) rand() / (double) rand() );
    }
}

void show_array_double(double *arr, int lenght) {

    int i = 0;
    for (i = 0; i < lenght; ++i) {
        printf(" %f ", arr[i]);
    }
    printf("\n**************************************\n");
}


