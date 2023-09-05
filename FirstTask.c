#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    while (1)
    {
        // This program calculates the average of numbers given by the user, no negative numbers allowed and 0 ends the feed.
        printf("Choose task to run:\n1. Average of numbers\n2. Salary calculator \n3. \n");
        int task;
        scanf("%d", &task);

        switch (task)
        {
        case 1:

            float number = 1.0;
            float sum = 0.0;
            int count = 0;
            float average = 0.0;

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
                    average = sum / count;
                    printf("The average is: %.1f\n", average);
                }
                else
                {
                    sum += number;
                    count++;
                }
            } while (number != 0);
            break;
        case 2:
            // This program takes monthly salaries in an array and calculates the yearly income
            float salaries[12]; // Change the data type to float
            float sum2 = 0.0;
            int i;

            for (i = 0; i < 12; i++)
            {
                printf("Give the salary of month %d\n", i + 1);
                scanf("%f", &salaries[i]); // Use %f to input float values
                sum2 += salaries[i];
                printf("Sum: %.2f\n", sum2);
            }
            for (i = 0; i < 12; i++)
            {
                printf("Month [%2d]: %.2f\n", i + 1, salaries[i]); // Use %f to print float values
            }
            printf("Yearly income: %.2f\n", sum2);
            break;
        case 3:

            int size;
            int array[size];
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
                    }
                    else
                    {
                        printf("Invalid grade!\n");
                    }
                    scanf("%d", &array[i]);
                }
            }

            break;

        default:
            printf("No such task!\n");
            break;
        }
    }
}