/*
6. Demonstrate example of Nested Structure in C language, how to define, declare and access the nested structure.
*/

#include <stdio.h>

struct Address {
    char city[100];
    char state[100];
};

struct Person {
    char name[100];
    int age;
    struct Address addr; // Nested structure
};

int main() {
    struct Person p;

    printf("Enter Name: ");
    scanf(" %[^\n]s", p.name);

    printf("Enter Age: ");
    scanf("%d", &p.age);

    printf("Enter City: ");
    scanf(" %[^\n]s", p.addr.city);

    printf("Enter State: ");
    scanf(" %[^\n]s", p.addr.state);

    printf("\nPerson Details:\n");
    printf("Name: %s\nAge: %d\nCity: %s\nState: %s\n", 
           p.name, p.age, p.addr.city, p.addr.state);
    return 0;
}