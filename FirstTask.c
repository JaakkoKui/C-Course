#include <stdio.h>
#include <stdlib.h>

#define months 12
#define studentNumber 45001

float number = 1.0;
float sum = 0.0;
float sum2 = 0.0;
float sum3 = 0.0;
int count = 0;
float salaries[months];
int i;

float average(float sum, int count);
float salaryCalc(int i);

float average(float sum, int count)
{
    float average;
    average = sum / count;
    return average;
}

float salaryCalc(int i)
{
    printf("Give the salary of month %d\n", i + 1);
    scanf("%f", &salaries[i]);
    if (salaries[i] < 0)
    {
        printf("No negative numbers\n");
    }
    else
    {
        sum2 += salaries[i];
        printf("Sum: %.2f\n", sum2);
    }
}

int main(void)
{
    // This is the main menu of the program, it asks the user to choose a task to run.
    while (1)
    {
        printf("Choose task to run:\n1. Average of given numbers\n2. Yearly salary calculator \n3. Student grader \n0. Exit\n");
        int task;
        if (scanf("%d", &task) != 1)
        {
            printf("Invalid input!\n");
            return 0;
        }

        switch (task)
        {

        // This calculates the average of numbers given by the user, no negative numbers allowed and 0 ends the feed.
        case 1:
            do
            {
                printf("Give numbers that you want the average calculated of one by one, no negative numbers and 0 ends the feed.\n");
                scanf("%f", &number);
                if (number < 0)
                {
                    printf("No negative numbers!\n");
                }
                else if (number == 0)
                {
                    printf("Average of given numbers: %.2f \n", average(sum, count));
                }
                else
                {
                    sum += number;
                    count++;
                }
            } while (number != 0);
            sum = 0;
            break;

        // This calculates the average of the monthly salaries given by the user, no negative numbers allowed.
        case 2:

            for (i = 0; i < 12; i++)
            {
                salaryCalc(i);
            }

            for (i = 0; i < 12; i++)
            {
                printf("Month [%2d]: %.2f\n", i + 1, salaries[i]);
            }
            printf("Average of monthly salary: %.2f \n", average(sum2, 12));
            printf("Yearly income: %.2f\n", sum2);
            sum2 = 0;
            break;

        // This calculates the average of the grades of students given by the user, numbers between 1 - 5 allowed.
        case 3:
            int size;
            printf("Give the number of students\n");
            scanf("%d", &size);

            if (size > 0)
            {
                int array[size];
                // intialize array with 0
                for (i = 0; i < size; i++)
                {
                    array[i] = 0;
                }

                printf("Give the grades of the students\n");
                for (i = 0; i < size; i++)
                {
                    int grade;
                    printf("Give grade of student %d\n", i + studentNumber);
                    scanf("%d", &grade);
                    if (grade > 0 && grade < 6)
                    {
                        array[i] = grade;
                        sum3 += grade;
                    }
                    else
                    {
                        printf("Invalid grade!\n");
                    }
                }
                for (i = 0; i < size; i++)
                {
                    printf("Student %d: %d\n", i + studentNumber, array[i]);
                }
                printf("Average of student grades: %.2f \n", average(sum3, size));
                sum3 = 0;
            }
            else
            {
                printf("No negative numbers\n");
            }
            break;

        // Ends the program.
        case 0:
            printf("The end.\n");
            return 0;

        default:
            printf("No such task!\n");
            break;
        }
    }
}