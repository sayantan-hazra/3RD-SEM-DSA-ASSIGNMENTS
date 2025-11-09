/*
4. Define a structure named "Date" with members day, month, and year. Write a C program to input two dates and find the difference in days between them.
*/

#include <stdio.h>
#include <time.h>

struct Date {
    int day;
    int month;
    int year;
};

int daysBetween(struct Date d1, struct Date d2) {
    struct tm tm1 = {0, 0, 0, d1.day, d1.month - 1, d1.year - 1900};
    struct tm tm2 = {0, 0, 0, d2.day, d2.month - 1, d2.year - 1900};
    time_t time1 = mktime(&tm1);
    time_t time2 = mktime(&tm2);
    return difftime(time2, time1) / (60 * 60 * 24);
}

int main() {
    struct Date d1, d2;

    printf("Enter Date 1 (dd mm yyyy): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);

    printf("Enter Date 2 (dd mm yyyy): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    int diff = daysBetween(d1, d2);
    printf("Difference: %d days\n", diff);
    return 0;
}