#ifndef DATEI_H_
#define DATEI_H_

void normalCaesar();
void encrypt();
void decrypt();

void bruteForceCaesar();
void bruteForceEncrypt();
void bruteForceDecrypt();

void encryptAndDecryptFile();
void encryptFile();
void decryptFile();

void helpFunctionEncryptFile(FILE *fp_in, FILE *fp_out, int key);
void helpFunctionDecryptFile(FILE *fp_in, FILE *fp_out, int key);
int readUserInput();
int printUserInput();
int pause();

#endif
