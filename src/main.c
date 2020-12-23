#include <stdio.h>
#include "header.h"

int main() {

    int menu;

    for(;;)
    {
        printf("***************Options***************\n\n");
        printf("| 1 | Normal Caesar-Encryption\n");
        printf("| 2 | Encryption and decryption with all possible key variants\n");
        printf("| 3 | Encryption and decryption of a file\n");
        printf("| 0 | Exit the program\n\n");
        printf("**************************************\n\n");

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
            normalCaesar();
            break;
        case 2:
            bruteForceCaesar();
            break;
        case 3:
            encryptAndDecryptFile();
            break;
        default:
            printf("Your input was invalid! \n");
            pause();
        }
    }
    printf("Goodbye!\n");
    return 0;
}
