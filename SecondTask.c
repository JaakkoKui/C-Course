#include <stdio.h>
#include <stdbool.h>

int main(void) {
    while (1) {
        printf("Choose task to run:\n4.Calulate scalar product of two given 3 number vectors. \n5.\n6.\n0. Exit\n");

        int task;
        if (scanf("%d", &task) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
        } else {
            switch (task) {
                case 4: {
                    printf("Enter numbers for vector 1:\n");
                    int n1, n2, n3;
                    if (scanf("%d %d %d", &n1, &n2, &n3) != 3) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                    } else {
                        printf("Enter numbers for vector 2:\n");
                        int m1, m2, m3;
                        if (scanf("%d %d %d", &m1, &m2, &m3) != 3) {
                            printf("Invalid input!\n");
                            while (getchar() != '\n');
                        } else {
                            printf("Numbers of vectors:\nVector 1: %d %d %d\nVector 2: %d %d %d\n", n1, n2, n3, m1, m2, m3);
                            int scalar = n1 * m1 + n2 * m2 + n3 * m3;
                            printf("Scalar product of vectors is %d\n\n", scalar);
                        }
                    }
                    break;
                }
                
                case 5: {
                    break;
                }

                case 6: {
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