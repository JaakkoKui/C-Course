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

struct Student
{
    char name[20];
    int studentNumber;
    char streetAdress[40];
    char city[20];
    float totalCredits;
};

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
        printf("Choose task to run:\n7. Cipher\n8. Student information\n6. \n0. Exit\n");
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
                const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
                const char reversedAlphabet[] = "zyxwvutsrqponmlkjihgfedcba";

                for (int i = 0; i < 26; i++)
                {

                    map[i].key = alphabet[i];
                    map[i].value = reversedAlphabet[i];
                }

                printf("Enter text to cipher: ");
                while (getchar() != '\n')
                    ;
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
                struct Student students[15] = {
                    {"Santeri", 666, "Nigeriapolku 90", "Nigeria", 0},
                    {"Jaska", 432, "Xhingxhong 22", "Kiina", 44},
                    {"Pekka", 672, "Keskikatu 2", "Suomi", 23},
                    {"Matti", 999, "Pingpong 4", "Thaimaa", 55},
                    {"Teppo", 111, "Gyros 5", "Kreikka", 12},
                    {"Jorma", 212, "Gyros 6", "Kreikka", 41},
                    {"Joonas", 515, "Zhangping 7", "Kiina", 22},
                    {"Jussi", 231, "Bangkok 852352", "Thaimaa", 99},
                    {"Jani", 777, "Mutaoja 77 B4", "Suomi", 32},
                    {"Mikko", 123, "Sakura 11", "Japani", 75},
                    {"Anna", 888, "Esplanadi 13 G66", "Suomi", 65},
                    {"Laura", 345, "Colosseum Ave.", "Italy", 50},
                    {"Hans", 567, "Brandenburg St.", "Saksa", 47},
                    {"Carlos", 456, "Siesta Lane", "Kreikka", 33},
                    {"Elena", 111, "Kremlin St.", "Venäjä", 28},
                };

                for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++)
                {
                    printf("Name: %s\nStudent number: %d\nStreet adress: %s\nCity: %s\nTotal credits: %.1f\n\n", students[i].name, students[i].studentNumber, students[i].streetAdress, students[i].city, students[i].totalCredits);
                }
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
