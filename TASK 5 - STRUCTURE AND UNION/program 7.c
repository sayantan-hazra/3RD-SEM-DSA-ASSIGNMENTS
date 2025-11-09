/*
7. Demonstrate example of pointer to structure, structure pointer in C.
*/

#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point p = {10, 20};
    struct Point *ptr = &p;

    printf("Coordinates: (%d, %d)\n", ptr->x, ptr->y);
    ptr->x = 30;
    ptr->y = 40;
    printf("Updated Coordinates: (%d, %d)\n", ptr->x, ptr->y);
    return 0;
}