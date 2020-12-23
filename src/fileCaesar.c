#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_TEXT_LENGTH 10000

void encryptAndDecryptFile()
{
    for(;;)
    {
        int menu;
        printf("**********************************\n\n");
        printf("| 1 | Encryption of a file\n");
        printf("| 2 | Decryption of a file\n");
        printf("| 0 | Back to the menu\n\n");
        printf("**********************************\n\n");

        printf("Choose an option: ");
        if ( scanf("%d", &menu) != 1  )
        {
            if ( feof(stdin) ) break;
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
            encryptFile();
            break;
        case 2:
            decryptFile();
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

void encryptFile()
{
    FILE *fp_in, *fp_out;
    char text[MAX_TEXT_LENGTH];
    int key;

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

            printf("Name of the file that has to be encrypt(.txt): ");
            scanf("%s", text);

            fp_in = fopen(text, "r");
            if (fp_in == NULL)
            {
                printf("The file couldn't be found. Check your file folder!\n");
                exit(1);
            }

            printf("Name of the target file(.txt): ");
            scanf("%s", text);
            fp_out = fopen(text, "w");
            if (fp_out == NULL)
            {
                printf("The file couldn't be found. Check your file folder!\n");
                exit(1);
            }
            helpFunctionEncryptFile(fp_in, fp_out, key);

            fclose(fp_in);
            fclose(fp_out);
            printf("\nThe file was successfully encrypted.");
            printUserInput();
            pause();
            return;
        }
    }
}

void decryptFile()
{
    FILE *fp_in, *fp_out;
    char text[MAX_TEXT_LENGTH];
    int key;

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
            printf("Name of the file that has to be decrypt(.txt): ");
            scanf("%s", text);
            fp_in = fopen(text, "r");

            if (fp_in == NULL)
            {
                printf("The file couldn't be found. Check your file folder!\n");
                exit(1);
            }
            printf("Name of the target file(.txt): ");
            scanf("%s", text);
            fp_out = fopen(text, "w");

            if (fp_out == NULL)
            {
                printf("The file couldn't be found. Check your file folder!\n");
                exit(1);
            }
            helpFunctionDecryptFile(fp_in, fp_out, key);
            fclose(fp_in);
            fclose(fp_out);
            printf("\nThe file was successfully decrypted.");
            printUserInput();
            pause();
            return;
        }
    }
}
