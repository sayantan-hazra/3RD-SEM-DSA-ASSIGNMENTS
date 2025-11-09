/*
3. Define a structure named "Time" with members hours, minutes, and seconds. Write a C program to input two times, add them, and display the result in proper time format.
*/

#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;
    result.seconds = t1.seconds + t2.seconds;
    result.minutes = t1.minutes + t2.minutes + (result.seconds / 60);
    result.hours = t1.hours + t2.hours + (result.minutes / 60);
    result.seconds %= 60;
    result.minutes %= 60;
    result.hours %= 24;
    return result;
}

int main() {
    struct Time t1, t2, sum;

    printf("Enter Time 1 (hh mm ss): ");
    scanf("%d %d %d", &t1.hours, &t1.minutes, &t1.seconds);

    printf("Enter Time 2 (hh mm ss): ");
    scanf("%d %d %d", &t2.hours, &t2.minutes, &t2.seconds);

    sum = addTime(t1, t2);
    printf("Sum of Time: %02d:%02d:%02d\n", sum.hours, sum.minutes, sum.seconds);
    return 0;
}