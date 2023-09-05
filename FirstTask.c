#include <stdio.h>
#include <stdlib.h>

float number = 1.0;
float sum = 0.0;
float sum2 = 0.0;
float sum3 = 0.0;
int count = 0;

float average(float sum, int count)
{
    float average;
    average = sum / count;
    return average;
}

int main(void)
{
    while (1)
    {
        // This program calculates the average of numbers given by the user, no negative numbers allowed and 0 ends the feed.
        printf("Choose task to run:\n1. Average of given numbers\n2. Yearly salary calculator \n3. Student grader \n");
        int task;
        scanf("%d", &task);

        switch (task)
        {
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
            break;

        case 2:
            float salaries[12];
            int i;

            for (i = 0; i < 12; i++)
            {
                printf("Give the salary of month %d\n", i + 1);
                scanf("%f", &salaries[i]);
                sum2 += salaries[i];
                printf("Sum: %.2f\n", sum2);
            }
            for (i = 0; i < 12; i++)
            {
                printf("Month [%2d]: %.2f\n", i + 1, salaries[i]);
            }
            printf("Average of monthly salary: %.2f \n", average(sum2, 12));
            printf("Yearly income: %.2f\n", sum2);
            break;

        case 3:
            int size;
            printf("Give the number of students\n");
            scanf("%d", &size);

            if (size > 0)
            {
                int array[size];
                printf("Give the grades of the students\n");
                for (i = 0; i < size; i++)
                {
                    int grade;
                    printf("Give grade of student %d\n", i + 45001);
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
                    printf("Student %d: %d\n", i + 45001, array[i]);
                }
                printf("Average of student grades: %.2f \n", average(sum3, size));
            }

            break;

        default:
            printf("No such task!\n");
            break;
        }
    }
}