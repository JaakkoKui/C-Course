#include <stdio.h>
#include <stdbool.h>


void ifIsInvalid() {
    printf("Invalid input!\n");
    while (getchar() != '\n');
}
int main(void) {
    while (1) {
        printf("Choose task to run:\n4.Calulate scalar product of two given 3 number vectors. \n5.\n6.\n0. Exit\n");
        int task;
        if (scanf("%d", &task) != 1) {
            ifIsInvalid();
        } else {
            switch (task) {
                case 4: {
                    printf("Enter numbers for vector 1:\n");
                    float n1, n2, n3;
                    if (scanf("%f %f %f", &n1, &n2, &n3) != 3) {
                        ifIsInvalid();
                    } else {
                        printf("Enter numbers for vector 2:\n");
                        float m1, m2, m3;
                        if (scanf("%f %f %f", &m1, &m2, &m3) != 3) {
                            ifIsInvalid();
                        } else {
                            printf("Numbers of vectors:\nVector 1: %g %g %g\nVector 2: %g %g %g\n", n1, n2, n3, m1, m2, m3);
                            float scalar = n1 * m1 + n2 * m2 + n3 * m3;
                            printf("Scalar product of vectors is %g \n\n", scalar);
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