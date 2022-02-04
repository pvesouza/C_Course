#include <stdio.h>
#include <stdlib.h>

#include "complex.h"

#define __STDC_WANT_LIB_EXT1__ 1

#define int char


int main()
{

    int i = 8;
    printf("%d", sizeof(i));

#ifdef __STDC_NP_COMPLEX__
    printf("No Complex Numbers supported\n");
#else
    printf("No Complex Numbers supported\n");

    Complex cx;
    cx.real = 1;
    cx.img = -5;

    printf("cx = %.2f %+.2fI\n", c_real(cx), c_img(cx));

    Complex c2;
    c2.img = 100;
    c2.real = 1;

    Complex result = add(cx, c2);

    printf("cx = %.2f %+.2fI\n", c_real(result), c_img(result));

    Complex conj;
    conj = conjugate(result);

    printf("cx = %.2f%+.2fI\n", c_real(conj), c_img(conj));

    return 0;

#endif // __STDC_NP_COMPLEX__
    return 0;
}
