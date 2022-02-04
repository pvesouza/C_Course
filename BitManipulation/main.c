#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <math.h>



void printBinary(int *number, int n);
long int convertBinToDec(int *pt, int size);
void revert(int *pointer, int n);
void decToBin(int value);


int main()
{
    int n = 0;
    int end = 1;
    int *pt = (int *)malloc(1 * sizeof(int));
    int value_aux = 0;

    while(end == 1){
        printf("Enter your binary number 0 or 1\n");

        scanf("%d", &value_aux);

        if ((value_aux != 0) && (value_aux != 1)){
            end = 0;
        }else{
            *(pt + n) = value_aux;
            n++;
            pt = (int *)realloc(pt, 1 * sizeof(int));
        }
    }

    printBinary(pt, n);
    unsigned long int result = convertBinToDec(pt, n);
    printf("The result is: %ld\n", result);
    decToBin((int)result);

    // Clear an specific bit
    result = result & (~16);
    printf("The result is: %ld\n", result);
    decToBin((int)result);

    result = result | (16);
    printf("The result is: %ld\n", result);
    decToBin((int)result);

    result = result << 4;
    printf("The result is: %ld\n", result);
    decToBin((int)result);

    result = result >> 4;
    printf("The result is: %ld\n", result);
    decToBin((int)result);

    return 0;
}

void printBinary(int *number, int n){
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%d", number[i]);
    }
    printf("\n");
}

long int convertBinToDec(int *pt, int size){
    long int result1 = 0;
    int i = 0;

    for (i = size - 1; i >= 0; i--){
        result1 += pt[i] * pow(2, (size - 1) - i);
        //printf("%ld---", result1);
    }
    return result1;
}

void decToBin(int value){

    int end = 1;
    int *pt_result = (int *) malloc(sizeof(int));
    int i = 0;

    while(end) {

        int rest = value % 2;
        //printf("rest = %d\n", rest);
        //printf("value = %d\n", value);
        value = value / 2;
        if (value == 0){
            pt_result[i] = rest;
            i++;
            revert(pt_result, i);
            printBinary(pt_result, i);
            end = 0;
        }else{
            pt_result[i] = rest;
            i++;
            realloc(pt_result, 1 * sizeof(int));
        }

    }
    free(pt_result);
}

void revert(int *pointer, int n) {

    int aux[n];
    // Copies the entire content to an aux pointer
    for (int i = 0; i < n; i++) {

        aux[i] = pointer[i];
    }

    //Realocates the entire content no pointer
    for (int i = 0; i < n; i++){
        pointer[(n - 1) - i] = aux[i];
    }

}
