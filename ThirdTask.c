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
                char text[100] = "";
                char cipheredText[100] = "";
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

                printf("Enter text to cipher:\n");
                while (getchar() != '\n');
                fgets(text, sizeof(text), stdin);
                printf("\n");
                for (int i = 0; i < strlen(text); i++)
                {
                    if (isalpha(text[i]))
                    { 
                        for (int j = 0; j < 26; j++)
                        {
                            if (text[i] == map[j].key)
                            {
                                cipheredText[i] = map[j].value;
                            }
                        }
                    }
                    else{
                        cipheredText[i] = text[i];
                    }
                }
                printf("Original text: %s\nCiphered text: %s\n", text, cipheredText);
                break;
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
