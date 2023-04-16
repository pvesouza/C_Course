#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "timeLib.c"

int main()
{
    showCurrentTime();
    showCurrentDate();
    printf("Time in seconds: %d\n", diffSecondsSinceCurrentMont());
    return 0;
}
