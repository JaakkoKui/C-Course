#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ifInvalidInput()
{
    printf("Invalid input!\n");
    while (getchar() != '\n')
        ;
}

struct keyValue
{
    char key;
    char value;
} map[26];

char *cipher(char *text, char *cipheredText, struct keyValue *map)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (isupper(text[i]) && text[i] == toupper(map[j].key))
                {
                    cipheredText[i] = toupper(map[j].value);
                }
                else if (text[i] == map[j].key)
                {
                    cipheredText[i] = map[j].value;
                }
            }
        }
        else
        {
            cipheredText[i] = text[i];
        }
    }
    return 0;
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
                const char text[100] = "";
                const char cipheredText[100] = "";
                const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
                const char reversedAlphabet[] = "zyxwvutsrqponmlkjihgfedcba";

                for (int i = 0; i < 26; i++)
                {

                    map[i].key = alphabet[i];
                    map[i].value = reversedAlphabet[i];
                }

                printf("Enter text to cipher: ");
                while (getchar() != '\n');
                fgets(text, sizeof(text), stdin);
                printf("\n");
                cipher(text, cipheredText, map);
                printf("Original text: %s\nCiphered text: %s\n", text, cipheredText);
                cipher(cipheredText, text, map);
                printf("Deciphered text: %s\n", text);
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
