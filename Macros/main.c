#include <stdio.h>
#include <stdlib.h>

#define PI 3.14
#define PRINT(a, b) \
    printf("value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);

#define CIRCLE_AREA(R) (PI * R * R)

int main()
{
    int x = 2;
    int y = 3;

    PRINT(x, y);

    double area = CIRCLE_AREA(4);

    printf("The area is %.2f\n", area);

    return 0;
}
