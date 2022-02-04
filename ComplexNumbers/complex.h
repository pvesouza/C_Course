#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED


struct _complex{
    double real;
    double img;
};

typedef struct _complex Complex;

double c_real(Complex c);
double c_img(Complex c);
Complex add(Complex c1, Complex c2);
Complex conjugate(Complex c);



#endif // COMPLEX_H_INCLUDED
