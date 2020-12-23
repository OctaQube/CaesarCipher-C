#include <stdio.h>

void helpFunctionEncryptFile(FILE *fp_in, FILE *fp_out, int key)
{
    int index;

    for(;;)
    {
        index = getc(fp_in);
        if(index == EOF)
            return;
        if(index >= 'a' && index <= 'z')
        {
            index = 'a' + ((index - 'a' + key) % 26);
        }
        else if(index >= 'A' && index <= 'Z')
        {
            index = 'A' + ((index - 'A' + key) % 26);
        }
        putc(index, fp_out);
    }
}

void helpFunctionDecryptFile(FILE *fp_in, FILE *fp_out, int key)
{
    int index;

    for(;;)
    {
        index = getc(fp_in);
        if(index == EOF)
            return;
        if(index >= 'a' && index <= 'z')
        {
            index = 'a' + ((index - 'a' + (26 - key)) % 26);
        }
        else if(index >= 'A' && index <= 'Z')
        {
            index = 'A' + ((index - 'A' + (26 - key)) % 26);
        }
        putc(index, fp_out);
    }
}

int readUserInput()
{
    int text;
    while ((text=getchar()) != '\n' && text != EOF);
    return text != EOF;
}

int printUserInput()
{
    int text;
    while ((text=getchar()) != '\n' && text != EOF)
        putchar(text);
    putchar('\n');
    return text != EOF;
}

int pause()
{
    printf("\nPress Enter to continue\n");
    return readUserInput();
}

