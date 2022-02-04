#include "calcs.h"
#include <stdio.h>

static double pi = 3.14;

 //Calcs the area of a circle
double circleArea(double radium){
    double area;
    static float area_1 = 0.0;
    area = pi * radium * radium;
    printf("persistent = %f\n", area_1 = 10 + area + area_1);
    return area;
}

 //Calcs the area of a circle
double circleArea2(double radium){
    double area;
    extern const double roundedPI;
    area = roundedPI * radium * radium;
    return area;
}

static double perimeter(float r){
    double perimeter;
    perimeter = 2 * pi * r;
    return perimeter;
}

void printPreimeter(){
    printf("Perimeter = %f\n", perimeter(5.5));
}

