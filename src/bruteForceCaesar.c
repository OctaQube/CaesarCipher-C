#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAX_TEXT_LENGTH 200

void bruteForceCaesar()
{
    for(;;)
    {
        int menu;
        printf("**********************************\n\n");
        printf("| 1 | Encryption\n");
        printf("| 2 | Decryption\n");
        printf("| 0 | Back to the menu\n\n");
        printf("**********************************\n\n");

        printf("Choose an option: ");
        if ( scanf("%d", &menu) != 1  )
        {
            if (feof(stdin)) break;
            printf("Your input was invalid! ");
            printUserInput();
            pause();
            continue;
        }
        readUserInput();

        if (menu == 0) break;

        switch(menu)
        {
        case 1:
            bruteForceEncrypt();
            break;
        case 2:
            bruteForceDecrypt();
            break;
        default:
            printf("Your input was invalid! \n");
            pause();
        }
    }
    printf("\n");
    printf("Go back to the menu.\n\n");
    return;
}

void bruteForceEncrypt()
{
    char stringToEncrypt[MAX_TEXT_LENGTH], outputString[MAX_TEXT_LENGTH], stringLenght;
    int key = 1, index;

    for(;;)
    {
        printf("Text to encrypt:");
        scanf("%s", stringToEncrypt);

        stringLenght = strlen(stringToEncrypt);
        if(stringLenght > MAX_TEXT_LENGTH)
        {
            printf("The text is too long!\n");
            readUserInput();
            pause();
        }
        else
        {
            printf("**********************************\n\n");
            while(key > 0 && key < 26)
            {
                int i;
                strcpy(outputString, stringToEncrypt);

                for(i = 0; outputString[i] != '\0'; ++i)
                {
                    index = outputString[i];

                    if(index >= 'a' && index <= 'z')
                    {
                        index = 'a' + ((index - 'a' + key) % 26);
                        outputString[i] = index;
                    }
                    else if(index >= 'A' && index <= 'Z')
                    {
                        index = 'A' + ((index - 'A' + key) % 26);
                        outputString[i] = index;
                    }
                }
                printf("Key number %d: %s\n", key, outputString);
                key++;
            }
            readUserInput();
            pause();
            return;
        }
    }
}

void bruteForceDecrypt()
{
    char stringToDecrypt[MAX_TEXT_LENGTH], outputString[MAX_TEXT_LENGTH], stringLenght;
    int key = 1, index;

    for(;;)
    {
        printf("Text to decrypt:");
        scanf("%s", stringToDecrypt);

        stringLenght = strlen(stringToDecrypt);
        if(stringLenght > MAX_TEXT_LENGTH)
        {
            printf("The text is too long!\n");
            readUserInput();
            pause();
        }
        else
        {
            printf("**********************************\n\n");
            while(key > 0 && key < 26)
            {
                int i;
                strcpy(outputString, stringToDecrypt);

                for(i = 0; outputString[i] != '\0'; ++i)
                {
                    index = outputString[i];

                    if(index >= 'a' && index <= 'z')
                    {
                        index = 'a' + ((index - 'a' + (26 - key)) % 26);
                        outputString[i] = index;
                    }
                    else if(index >= 'A' && index <= 'Z')
                    {
                        index = 'A' + ((index - 'A' + (26 - key)) % 26);
                        outputString[i] = index;
                    }
                }
                printf("Key number %d: %s\n", key, outputString);
                key++;
            }
            readUserInput();
            pause();
            return;
        }
    }
}
