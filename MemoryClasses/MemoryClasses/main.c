#include <stdio.h>
#include <stdlib.h>
#include "calcs.h"


int main()
{
    int i = 10;

    for (register int i = 0; i < 100; i++){
        printf("Local: %d\n", i);
    }

    printf("Main: %d\n", i);

    printf("Area 1 = %f\n", circleArea(4.0));
    printf("Area 1 = %f\n", circleArea(4.0));
    printf("Area 2 = %f\n", circleArea2(4.0));

    printPreimeter();
    extern const double roundedPI;
    extern const double pi2;
    double _pi2 = roundedPI;
    printf("Pi: %f", _pi2);
    return 0;
}
