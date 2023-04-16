#ifndef TIMELIB_H_INCLUDED
#define TIMELIB_H_INCLUDED

#include <time.h>
#include <assert.h>
#include <stdio.h>

void showCurrentTime(void);
void showCurrentDate(void);
int diffSecondsSinceCurrentMont(void);


extern const char MONTHS[12][4];
extern const char WEEKDAYS[7][4];


#endif // TIMELIB_H_INCLUDED
