/*
1. Demonstrate a structure named Book, Details (B_id [integer], title [string], author [string], price [float]) and display them by taking 3 different books. Also find the average price of each book.
*/

#include <stdio.h>

struct Book {
    int B_id;
    char title[100];
    char author[100];
    float price;
};

int main() {
    struct Book books[3];
    float total = 0;

    for (int i = 0; i < 3; i++) {
        printf("Enter details for Book %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &books[i].B_id);
        printf("Title: ");
        scanf(" %[^\n]s", books[i].title);
        printf("Author: ");
        scanf(" %[^\n]s", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
        total += books[i].price;
    }

    printf("\nBook Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Book %d: ID=%d, Title=%s, Author=%s, Price=%.2f\n", 
               i + 1, books[i].B_id, books[i].title, books[i].author, books[i].price);
    }

    printf("Average Price: %.2f\n", total / 3);
    return 0;
}