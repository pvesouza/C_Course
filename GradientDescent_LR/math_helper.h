#ifndef MATH_HELPER_H_INCLUDED
#define MATH_HELPER_H_INCLUDED

#include <math.h>

extern double alpha;

double mean(double *dataSet, int n_samples) {

    double sum = 0.0;
    for (int i = 0; i < n_samples; i++) {
        sum = sum + *(dataSet + i);
    }
    return sum / n_samples;
}

double stdeviation(double *dataSet, int n_samples) {

    double _mean = mean(dataSet, n_samples);
    double sum = 0.0;

    for (int i = 0; i < n_samples; i++) {
        double xi = *(dataSet + i);
        xi = (xi - _mean);
        sum = sum + pow(xi, 2);
    }

    sum = sum / (n_samples - 1);
    return sqrt(sum);
}

void normalizeDataSet(double *dataSet, int n_samples) {
    double _mean = mean(dataSet, n_samples);
    double _stdeviation = stdeviation(dataSet, n_samples);
    double value = 0.0;
    //printf("Mean: %f Std: %f", _mean, _stdeviation);

    for (int i = 0; i < n_samples; i++) {
        value = *(dataSet + i);
        value = (value - _mean) / _stdeviation;
        *(dataSet + i) = value;
    }
}

double hipothesis(double theta_0, double theta_1, double x) {
    return x * theta_1 + theta_0;
}

double calcTheta0(double *xi, double *yi, int n_samples, double theta0, double theta1) {
    double sum = 0.0;
    for (int i = 0; i < n_samples; i++) {
        double x = *(xi + i);
        double y = *(yi + i);
        double h = hipothesis(theta0, theta1, x);
        sum = sum + (h - y);
        //printf("%f    %f   % f   %f\n", x, y, h, sum);
    }

    return ((sum * alpha) / n_samples);
}

double calcTheta1(double *xi, double *yi, int n_samples, double theta0, double theta1) {
    double sum = 0.0;

    for (int i = 0; i < n_samples; i++) {
        double x = *(xi + i);
        double y = *(yi + i);
        double h = hipothesis(theta0, theta1, x);
        sum = sum + (h - y) * x;
    }

    return ((sum * alpha) / n_samples);
}

double costFunction(double *xi, double *yi, int n_samples, double theta0, double theta1) {
    double sum = 0.0;

    for (int i = 0; i < n_samples; i++) {
        double x = *(xi + i);
        double y = *(yi + i);
        double h = hipothesis(theta0, theta1, x);
        sum = sum + pow((h - y), 2);
    }
    return (sum  / (2 * n_samples));
}

double unormalize(double x, double mean, double stdDev) {
    double value = 0.0;
    value = x * stdDev + mean;
    return value;
}





#endif // MATH_HELPER_H_INCLUDED
