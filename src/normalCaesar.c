#include <stdio.h>
#include <string.h>
#include "header.h"

#define MAX_TEXT_LENGTH 200

void normalCaesar()
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
        if (scanf("%d", &menu) != 1)
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
            encrypt();
            break;
        case 2:
            decrypt();
            break;
        default:
            printf("Your input was invalid! \n");
            pause();
        }
    }
    printf("\n");
    printf("Back to the menu.\n\n");
    return;
}

void encrypt()
{
    char stringToEncrypt[MAX_TEXT_LENGTH], stringLenght;
    int index, key, i;

    for(;;)
    {
        printf("Key(1-25): ");
        scanf("%d", &key);
        fflush(stdin);

        if(key < 1 || key > 25)
        {
            printf("Your input was invalid!\n");
            pause();
        }
        else
        {
            printf("Message to encrypt: ");
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
                for(i = 0; stringToEncrypt[i] != '\0'; ++i)
                {
                    index = stringToEncrypt[i];

                    if(index >= 'a' && index <= 'z')
                    {
                        index = 'a' + ((index - 'a' + key) % 26);
                        stringToEncrypt[i] = index;
                    }
                    else if(index >= 'A' && index <= 'Z')
                    {
                        index = 'A' + ((index - 'A' + key) % 26);
                        stringToEncrypt[i] = index;
                    }
                }
                printf("The encrypted message is: %s\n", stringToEncrypt);
                readUserInput();
                pause();
                return;
            }
        }
    }
}

void decrypt()
{
    char stringToDecrypt[MAX_TEXT_LENGTH], stringLenght;
    int index, key, i;

    for(;;)
    {
        printf("Key(1-25): ");
        scanf("%d", &key);
        fflush(stdin);
        if(key < 1 || key > 25)
        {
            printf("Your input was invalid!\n");
            pause();
        }
        else
        {
            printf("Message to decrypt: ");
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
                for(i = 0; stringToDecrypt[i] != '\0'; ++i)
                {
                    index = stringToDecrypt[i];

                    if(index >= 'a' && index <= 'z')
                    {
                        index = 'a' + ((index - 'a' + (26 - key)) % 26);
                        stringToDecrypt[i] = index;
                    }
                    else if(index >= 'A' && index <= 'Z')
                    {
                        index = 'A' + ((index - 'A' + (26 - key)) % 26);
                        stringToDecrypt[i] = index;
                    }
                }
                printf("The decrypted message is: %s\n", stringToDecrypt);
                readUserInput();
                pause();
                return;
            }
        }
    }
}
