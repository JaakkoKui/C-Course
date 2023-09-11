#include <stdio.h>
#include <stdbool.h>

int main(void) {
    while (1) {
        printf("Choose task to run:\n1.\n2.\n3.\n0. Exit\n");

        int task;
        if (scanf("%d", &task) != 1) {
            printf("Invalid input!\n");
            while (getchar() != '\n');
        } else {
            switch (task) {
                case 1: {
                    break;
                }
                
                case 2: {
                    break;
                }

                case 3: {
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