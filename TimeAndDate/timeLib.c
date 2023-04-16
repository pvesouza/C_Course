#include "TimeLib.h"

const char MONTHS[12][4] = {
    "Jan",
    "Feb",
    "Mar",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec"
};

const char WEEKDAYS[7][4] = {
    "Sun",
    "Mon",
    "Tue",
    "Wed",
    "Thr",
    "Fri",
    "Sat"
};

void showCurrentTime(void) {
    time_t t;
    time(&t);
    char time[26];
    const char *current_time = ctime(&t);

    if (current_time == NULL){
        fprintf(stdout, "Error code: %d\n", 0);
        exit(EXIT_FAILURE);
    }else {
        strcpy(time, current_time);
        fprintf(stdout, "%s\n", time);
    }
}
void showCurrentDate(void) {
    time_t t;
    time(&t);
    struct tm *stm = localtime(&t);
    if (stm == NULL) {
        printf("Error Getting time\n");
        exit(0);
    }
    int year = stm->tm_year + 1900;
    int day = stm->tm_mday;
    int weekday = stm->tm_wday;
    int month = stm->tm_mon;

    fprintf(stdout, "%s %d/%s/%d\n", WEEKDAYS[weekday], day, MONTHS[month], year);
}

int diffSecondsSinceCurrentMont(void) {
    time_t t_end, t_start;
    struct tm *tm_end, tm_start;

    time(&t_end);
    tm_end = localtime(&t_end);

    tm_start = *tm_end;
    tm_start.tm_hour = 0;
    tm_start.tm_mday = 1;
    tm_start.tm_sec = 0;
    tm_start.tm_min = 0;

    t_start = mktime(&tm_start);

    return difftime(t_end,t_start);

}
