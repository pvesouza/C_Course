#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <malloc.h>

// This program implements an example of variadic function

double average(int i, ...);                     // This function receives at least 1 arguments
double std_deviation(int count, ...);           // This function calculates the standard deviation of n given numbers
int adding_integers(int n, ...);                // This function adds n integers in variadic way

int main()
{

    double v1 = 10.0;

    double avg = average(6, v1, v1, v1, v1, v1, v1);
    double std_deviation1 = std_deviation(6, v1, v1, v1, v1, v1, v1);

    printf("The average is %.2f and the standard deviation is %f\n", avg, std_deviation1);

    printf("The sum if %d\n", adding_integers(2, 10, 20));
    printf("The sum if %d\n", adding_integers(3, 10, 20, 30));
    printf("The sum if %d\n", adding_integers(4, 10, 20, 30, 40));

    return 0;
}


double average(int n, ...) {

    va_list parg;                   // Variable to store the last argument of the list
    double sum = 0;
    int i = 0;

    va_start(parg, n);             // Says which is the address of the last argument

    for (i = 0; i < n; i++){

        double value = va_arg(parg, double);
        //printf("%f\n", value);
        sum = sum + value;
    }

    va_end(parg);               // Clears all the data

    return sum / n;
}

double std_deviation(int count, ...) {

    double std_deviation = 0;
    double sum = 0;

    va_list pt_args;                         // List of arguments
    va_list pt_args_copy;                    // Copy of the list of arguments
    va_start(pt_args, count);
    va_copy(pt_args_copy, pt_args);

    // calcs the average of the arguments
    for (int i = 0; i < count; i++){
        sum = sum + va_arg(pt_args, double);
    }

    va_end(pt_args);

    double mean = sum / count;
    double sum_square_diff = 0;

    // calcs the average of the arguments
    for (int i = 0; i < count; i++){
        double value = va_arg(pt_args_copy, double);
        sum_square_diff = sum_square_diff + ((value - mean) * (value - mean));
    }

    va_end(pt_args_copy);

    std_deviation = sqrt(sum_square_diff);


    return std_deviation;

}

int adding_integers(int n, ...) {
    int sum = 0;

    va_list pt_args;
    va_start(pt_args, n);

    for (int i = 0; i < n; i++) {

        int value = va_arg(pt_args, int);
        sum = sum + value;
    }

    return sum;
}
