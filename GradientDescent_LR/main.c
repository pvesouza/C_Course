#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <stdbool.h>

#include "math_helper.h"

#define CONVERGENCE 0.001
#define ALPHA 0.1;
#define MAX_EPHOCHS = 500
// This code represents the Gradient Descent Algorithm implemented in C language
// over a Linear Regression

double alpha = ALPHA;               // Learning rate
double __theta0;                    // Theta0 after gradient descent
double __theta1;                    // Theta1 after gradient descent
int m = 5;                          // Number of sample points

void printDataSet(double *dataSet, int length);
void gradientDescent(double *xi, double *yi, double theta0_initial, double theta1_initial);

int main()
{

    double xi[] = {
        2158.70,
        1708.30,
        2165.20,
        2053.50,
        1753.70
    };                  // Vector xi of the training set

    double yi[] = {
        15.50,
        19.00,
        13.00,
        18.00,
        21.50
    };                  // Vector yi of the training set

    double myMean = mean(yi, m);
    double myStdDeviation = stdeviation(yi, m);

    normalizeDataSet(xi, m);
    normalizeDataSet(yi, m);
    printDataSet(xi, m);
    printDataSet(yi, m);

    gradientDescent(xi, yi, 0.0, 0.0);

    double cost = costFunction(xi, yi, m, __theta0, __theta1);
    //__theta0 = unormalize(__theta0, myMean, myStdDeviation);
    //__theta1 = unormalize(__theta1, myMean, myStdDeviation);

    printf("J(%.2f,%.2f) = %.2f\n", __theta0, __theta1, cost);

    for (int i = 0; i < m; i++) {
        double hx = hipothesis(__theta0, __theta1, xi[i]);
        double hxNormal = unormalize(hx, myMean, myStdDeviation);
        printf("h(x) = %.2f\n", hx);
        printf("h(x) = %.2f\n", hxNormal);
    }

    return 0;
}

void printDataSet(double *dataSet, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d %.2f\n", i + 1, dataSet[i]);
    }
    printf("------------------------------------------------\n");
}

void gradientDescent(double *xi, double *yi, double theta0_initial, double theta1_initial) {

    int ephocs = 0;
    double theta0_temp;
    double theta1_temp;
    double theta0 = theta0_initial;
    double theta1 = theta1_initial;
    bool end = false;

    while(!end) {
        theta0_temp = theta0 - calcTheta0(xi, yi, m, theta0, theta1);
        theta1_temp = theta1 - calcTheta1(xi, yi, m, theta0, theta1);
        ephocs++;

        double dif0 = fabs(theta0 - theta0_temp);
        double dif1 = fabs(theta1 - theta1_temp);

        if ((dif0 < CONVERGENCE && dif1 <= CONVERGENCE) || ephocs > 500) {
            end = true;
        }else {
            // Updates both theta simultaneosly
            theta0 = theta0_temp;
            theta1 = theta1_temp;
        }
        printf("%d- (%.2f, %.2f)\n", ephocs, theta0, theta1);
        printf("J(%.2f, %.2f) = %f\n", theta0, theta1, costFunction(xi, yi, m, theta0, theta1));
    }
    __theta0 = theta0;
    __theta1 = theta1;
}


