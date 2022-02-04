#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Enum with months
enum Month {JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};
enum WeekDay {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THRUSDAY, FRIDAY, SATURDAY};
static const char days[7][10];

typedef enum Month Month;
typedef enum WeekDay WeekDay;

struct date{
    Month month;
    WeekDay weekday;
    int year;
    int day;
};

typedef struct date Date;

Date dateUpdate(Date today);
int numberOfDays(Date d);
bool isLeapYear(int d);
bool isThirdOneMonth(Month m);
Date newDate(Month m, WeekDay w, int year);
WeekDay newDay(WeekDay w);
void printDate(Date d);





#endif // DATE_H_INCLUDED
