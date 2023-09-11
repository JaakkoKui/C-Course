#include <stdio.h>
#include <stdbool.h>

#define MAX_MONTHS 12
#define MAX_STUDENTS 100

struct Student {
    int id;
    int grade;
};

float average(float sum, int count);

float average(float sum, int count) {
    return (count > 0) ? (sum / count) : 0;
}

int main(void) {
    while (1) {
        printf("Choose task to run:\n1. Average of given numbers\n2. Yearly salary calculator\n3. Student grader\n0. Exit\n");

        int task;
        if (scanf("%d", &task) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
        } else {
            switch (task) {
                case 1: {
                    // This calculates the average of the given numbers, no negative numbers or letters, 0 ends the feed
                    float number = 1.0;
                    float sum = 0.0;
                    int count = 0;
                    bool done = false;
                    while(1) {
                        printf("Give numbers that you want the average calculated of one by one, no negative numbers or letters, 0 ends the feed.\n");
                        if (scanf("%f", &number) != 1) {
                            printf("Invalid input!\n");
                            while (getchar() != '\n');
                        } else if (number < 0) {
                            printf("No negative numbers!\n");
                        } else if (number == 0) {
                            printf("Average of given numbers: %.2f\n", average(sum, count));
                            break;
                        } else {
                            sum += number;
                            count++;
                        }
                    }
                    break;
                }
                
                case 2: {
                    // This calculates the average of the given salaries and the total yearly income, no negative numbers or letters
                    float salaries[MAX_MONTHS];
                    float yearlyTotal = 0.0;

                    for (int i = 0; i < MAX_MONTHS; i++) {
                        printf("Give the salary of month %d\n", i + 1);
                        float salary;
                        if (scanf("%f", &salary) != 1 || salary < 0) {
                            printf("Invalid input!\n");
                            while (getchar() != '\n');
                            i--;
                        } else {
                            yearlyTotal += salary;
                            salaries[i] = salary;
                        }
                    }

                    for (int i = 0; i < MAX_MONTHS; i++) {
                        printf("Month [%2d]: %.2f\n", i + 1, salaries[i]);
                    }
                    printf("Average of monthly salary: %.2f\n", average(yearlyTotal, MAX_MONTHS));
                    printf("Yearly income: %.2f\n", yearlyTotal);
                    break;
                }

                case 3: {
                    // This calculates the average of the given grades and prints them out, no negative numbers or letters
                    int size;
                    printf("Give the number of students (1-%d)\n", MAX_STUDENTS);
                    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_STUDENTS) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                    } else {
                        struct Student students[MAX_STUDENTS];
                        float gradesTotal = 0.0;

                        printf("Give the grades (0-5) of the students\n");
                        for (int i = 0; i < size; i++) {
                            printf("Give grade (0-5) of student: %d\n", i + 1);
                            int grade;
                            if (scanf("%d", &grade) != 1 || grade < 0 || grade > 5) {
                                printf("Invalid grade!\n");
                                while (getchar() != '\n');
                                i--;
                            } else {
                                students[i].id = i + 1;
                                students[i].grade = grade;
                                gradesTotal += grade;
                            }
                        }

                        for (int i = 0; i < size; i++) {
                            printf("Student %d: Grade %d\n", students[i].id, students[i].grade);
                        }
                        printf("Average of student grades: %.1f\n", average(gradesTotal, size));
                    }
                    break;
                }

                case 0:
                    printf("The end.\n");
                    return 0;

                default:
                    printf("No such task!\n");
                    break;
            }
        }
    }
}