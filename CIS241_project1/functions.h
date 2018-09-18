#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <ctype.h>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNUM 27

char *removeDuplicates(char *word);

int targetFound(char *charArray, int num, char target);

void initializeEncryptArray(char *key, char *encrypt);

void initializeDecryptArray(char *encrypt, char *decrypt);

void processInput(FILE *inf, FILE *outf, char *substitute);

#endif // FUNCTIONS_H_
