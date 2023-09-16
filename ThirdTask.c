#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ifInvalidInput()
{
    printf("Invalid input!\n");
    while (getchar() != '\n')
        ;
}

int main(void)
{
    while (1)
    {
        printf("Choose task to run:\n7.Cipher\n8.\n6.\n0. Exit\n");
        int task;
        if (scanf("%d", &task) != 1)
        {
            ifInvalidInput();
        }
        else
        {
            switch (task)
            {
            case 7:
            {
                
                struct keyValue
                {
                    char key;
                    char value;
                } map[26];

                char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
                char reversedAlphabet[] = "zyxwvutsrqponmlkjihgfedcba";

                for (int i = 0; i < 26; i++)
                {
                    map[i].key = alphabet[i];
                    map[i].value = reversedAlphabet[i];
                }

                for (int i = 0; i < 26; i++)
                {
                    printf("%c -> %c\n", map[i].key, map[i].value);
                }
                printf(map);
            }
            case 8:
            {
                break;
            }

            case 9:
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
