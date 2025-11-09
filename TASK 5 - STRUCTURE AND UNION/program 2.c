/*
2. Create a structure called "Student" with members s_id, name, age, and total marks. Write a C program to input an array of five students, display their information, and find the names of students who secured highest and lowest score.
*/

#include <stdio.h>

struct Student {
    int s_id;
    char name[100];
    int age;
    int total_marks;
};

int main() {
    struct Student students[5];
    int max = -1, min = 101;
    char max_name[100], min_name[100];

    for (int i = 0; i < 5; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].s_id);
        printf("Name: ");
        scanf(" %[^\n]s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Total Marks: ");
        scanf("%d", &students[i].total_marks);

        if (students[i].total_marks > max) {
            max = students[i].total_marks;
            strcpy(max_name, students[i].name);
        }
        if (students[i].total_marks < min) {
            min = students[i].total_marks;
            strcpy(min_name, students[i].name);
        }
    }

    printf("\nStudent Details:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: ID=%d, Name=%s, Age=%d, Marks=%d\n", 
               i + 1, students[i].s_id, students[i].name, students[i].age, students[i].total_marks);
    }

    printf("Highest Scorer: %s (%d)\n", max_name, max);
    printf("Lowest Scorer: %s (%d)\n", min_name, min);
    return 0;
}