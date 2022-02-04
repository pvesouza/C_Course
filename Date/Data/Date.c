#include "Date.h"
#include <stdbool.h>

static const char days[7][10] = {
    {"Sunday"},
    {"Monday"},
    {"Tuesday"},
    {"Wednesday"},
    {"Thursday"},
    {"Friday"},
    {"Saturday"}};

bool isLeapYear(int d){

    return (d % 4 == 0);
}


Date dateUpdate(Date today) {

    Date tomorrow;
    WeekDay w = today.weekday;
    Month m = today.month;
    int year = today.year;
    int day = today.day;

    //Set the day after
    if (isLeapYear(year)){
        // Test if the current month is 31
        if (isThirdOneMonth(m)){
            // Test if day is 31
            if (day == 31){
                day = 1;
                //Tests if it is a new year
                if (m == DECEMBER){
                    m = JANUARY;
                    year = year + 1;
                }else{
                    m = m + 1;
                }
            }else{
                day = day + 1;
            }

            w = newDay(w);

        }else if (m == FEBRUARY){
            // Test if day is 29
            if (day == 29){
                day = 1;
                m = m + 1;

            }else{
                day = day + 1;
            }

            w = newDay(w);
        }else{
            // Test if day is 30
            if (day == 30){
                day = 1;
                m = m + 1;

            }else{
                day = day + 1;
            }

            w = newDay(w);
        }

    }else{

        // Test if the current month is 31
        if (isThirdOneMonth(m)){
            // Test if day is 31
            if (day == 31){
                day = 1;
                //Tests if it is a new year
                if (m == DECEMBER){
                    m = JANUARY;
                    year = year + 1;
                }else{
                    m = m + 1;
                }
            }else{
                day = day + 1;
            }

            w = newDay(w);

        }else if (m == FEBRUARY){
            // Test if day is 29
            if (day == 28){
                day = 1;
                m = m + 1;

            }else{
                day = day + 1;
            }

            w = newDay(w);
        }else{
            // Test if day is 30
            if (day == 30){
                day = 1;
                m = m + 1;

            }else{
                day = day + 1;
            }

            w = newDay(w);
        }

    }
    tomorrow = newDate(m, w, year);
    tomorrow.day = day;

    return tomorrow;
}
// Creates a new date given a Month, a Weekday and an year
Date newDate(Month m, WeekDay w, int year){

    Date d;
    d.month = m;
    d.weekday = w;
    d.year = year;

    return d;

}

//Given a month it returns if it it 30 or 31
bool isThirdOneMonth(Month m){

    bool result = false;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){

        result = true;
    }

    return result;
}

// Returns a new date
WeekDay newDay(WeekDay w){
    if (w == SATURDAY){
        return SUNDAY;
    }

    return w = w + 1;
}

void printDate(Date d){
    //Format (dd-MM-yyyy)
    if (d.day < 9){
        printf("0%d--", d.day);
    }else{
        printf("%d--", d.day);
    }

    if (d.month < OCTOBER){
        printf("0%d--", d.month);

    }else{
        printf("%d--", d.month);
    }

    printf("%d ", d.year);
    printf("%s\n", days[d.weekday]);

}


