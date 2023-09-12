#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void ifInvalidInput()
{
    printf("Invalid input!\n");
    while (getchar() != '\n')
        ;
}

void replaceWhitespaceWithUnderscore(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
    }
}

int main(void)
{
    while (1)
    {
        printf("Choose task to run:\n4. Calculate scalar product of two given 3 number vectors.\n5. Given strings white space to underscores.\n6.\n0. Exit\n");
        int task;
        if (scanf("%d", &task) != 1)
        {
            ifInvalidInput();
        }
        else
        {
            switch (task)
            {
            case 4:
            {
                printf("Enter numbers for vector 1:\n");
                float n1, n2, n3;
                if (scanf("%f %f %f", &n1, &n2, &n3) != 3)
                {
                    ifInvalidInput();
                }
                else
                {
                    printf("Enter numbers for vector 2:\n");
                    float m1, m2, m3;
                    if (scanf("%f %f %f", &m1, &m2, &m3) != 3)
                    {
                        ifInvalidInput();
                    }
                    else
                    {
                        printf("Numbers of vectors:\nVector 1: %g %g %g\nVector 2: %g %g %g\n", n1, n2, n3, m1, m2, m3);
                        float scalar = n1 * m1 + n2 * m2 + n3 * m3;
                        printf("Scalar product of vectors is %g \n\n", scalar);
                    }
                }
                break;
            }

            case 5:
            {
                char inputString[101];

                printf("Give string(Max 100 characters). STOP/stop ends the program: ");
                getchar(); // Consume the newline character left in the buffer
                fgets(inputString, sizeof(inputString), stdin);

                // Remove the trailing newline character if present
                size_t len = strlen(inputString);
                if (len > 0 && inputString[len - 1] == '\n')
                {
                    inputString[len - 1] = '\0';
                }

                char stop[] = "stop";
                char STOP[] = "STOP";

                if (strncmp(stop, inputString, 4) != 0 && strncmp(STOP, inputString, 4) != 0)
                {
                    replaceWhitespaceWithUnderscore(inputString);
                    printf("Modified string: %s\n", inputString);
                }
                else
                {
                    printf("Program stopped.\n");
                }
                break;
            }

            case 6:
            {
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