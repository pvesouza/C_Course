#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int returnRamdomNumber(int min, int max);
int main()
{
    time_t t, *pt_t;
    pt_t = &t;
    struct tm *date_info;
    int i = 0;

    time(pt_t);
    date_info = localtime(pt_t);
    printf("Current local time and date: %s", asctime(date_info));

    srand(time(NULL));

    for (i = 0; i < 50; i++) {
        double decimalRandom = returnRamdomNumber(-5000, 5000) / 10000.0;
        printf("%.4lf \n", decimalRandom);
    }

    return 0;
}

int returnRamdomNumber(int min, int max) {

    int low = 0, high = 0;
    if (min < max) {
        low = min;
        high = max;
    }else {
        low = max;
        high = min;
    }
    return (rand() % (high - low) + low);
}
