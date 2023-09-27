#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ifInvalidInput()
{
    printf("Invalid input!\n");
    while (getchar() != '\n');
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
int amount = 0;
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

int findInCity(struct Student *students, int size, char *city)
{

    for (int i = 0; i < size; i++)
    {
        if (stricmp(students[i].city, city) == 0)
        {
            printf("%-15s %5d %-20s %-10s %5.1f\n", students[i].name, students[i].studentNumber, students[i].streetAdress, students[i].city, students[i].totalCredits);
            amount++;
        }
    }
    return amount;
}

int main(void)
{
    while (1)
    {
        printf("Choose task to run:\n7. Cipher\n8. Student information\n9. Item prices\n0. Exit\n");
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
                char findCity[20];
                struct Student students[15] = {
                    {"Santeri", 666, "Mannerheimintie 1", "Helsinki", 0},
                    {"Jaska", 432, "Esplanadi 2", "Espoo", 44},
                    {"Pekka", 672, "Aleksanterinkatu 3", "Tampere", 23},
                    {"Matti", 999, "Rautatienkatu 4", "Turku", 55},
                    {"Teppo", 111, "Kauppakatu 5", "Oulu", 12},
                    {"Jorma", 212, "Kirkkokatu 6", "Helsinki", 41},
                    {"Joonas", 515, "Hameenkatu 7", "Lahti", 22},
                    {"Jussi", 231, "Hameenkatu 8", "Kuopio", 99.5},
                    {"Jani", 777, "Helsinginkatu 9", "Lahti", 32},
                    {"Mikko", 123, "Kauppakatu 10", "Oulu", 75},
                    {"Anna", 888, "Keskuskatu 11", "Helsinki", 65},
                    {"Laura", 345, "Kauppatori 12", "Turku", 50},
                    {"Hans", 567, "Helsinginkatu 13", "Tampere", 47},
                    {"Carlos", 456, "Kirkkokatu 14", "Tampere", 33},
                    {"", 0, "", "", 0}};
                int found = 0;
                int sizeOfS = sizeof(students) / sizeof(students[0]);

                for (int i = 0; i < sizeOfS; i++)
                {
                    if (students[i].studentNumber != 0)
                    {
                        printf("Name: %s\nStudent number: %d\nStreet adress: %s\nCity: %s\nTotal credits: %.1f\n\n", students[i].name, students[i].studentNumber, students[i].streetAdress, students[i].city, students[i].totalCredits);
                    }
                }

                while (1)
                {
                    printf("Enter city to search: \n\n");
                    scanf("%s", findCity);
                    if (stricmp(findCity, "stop") == 0)
                    {
                        break;
                    }
                    found = findInCity(students, sizeOfS, findCity);
                    if (found == 0)
                    {
                        printf("No students live in given city.\n\n");
                    }
                    else
                    {
                        printf("Students living in given city found: %d\n\n", found);
                        amount = 0;
                    }
                }
            }

            case 9:
            {

                printf("%ld\n", __STDC_VERSION__);
                return 0;
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
