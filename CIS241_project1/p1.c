#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "functions.h"

int main(int argc, char* argv[]){
	char choice, ch;
	FILE *fin, *fout;
	
	if (argc != 5){
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Choose option e for encryption and d for decryption");
		exit(1);
	}

	choice = toupper(*argv[1]);
	char *key = (char*)malloc(sizeof(argv[2]) + sizeof(char));
	key = removeDuplicates(argv[2]);
	
	char *encrypt = (char*)malloc(27 * sizeof(char));
	char *decrypt = (char*)malloc(27 * sizeof(char));
	initializeEncryptArray(key, encrypt);

	 fin = fopen(argv[3], "r");
         fout = fopen(argv[4], "w");
         if(fin == NULL || fout == NULL){
                printf("File could not be opened \n");
                exit(1);
        }
  	if(choice  == 'E')
		processInput(fin, fout, encrypt);
	if(choice == 'D'){		
		initializeDecryptArray(encrypt, decrypt);
		processInput(fin, fout, decrypt);
  	}
	fclose(fin);
	fclose(fout);

	return 0;
}
