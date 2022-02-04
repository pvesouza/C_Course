#include "complex.h"

double c_real(Complex c){
    return c.real;
}

double c_img(Complex c){
    return c.img;
}

Complex add(Complex c1, Complex c2){
    Complex c_result;
    c_result.img = c1.img + c2.img;
    c_result.real = c1.real + c2.real;

    return c_result;
}

Complex conjugate(Complex c){
    Complex result;
    result.real = c.real;
    result.img = -1 * c.img;
    return result;
}





