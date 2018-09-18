#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void initializeEncryptArray(char *key, char *encrypt){
	int i, j;
	char *keyChange = (char*)malloc(strlen(key));
	keyChange = removeDuplicates(key);
	for(i = 0; i < (strlen(keyChange)); i++){
		encrypt[i] = keyChange[i];
	}
	char temp = 'Z';
	for(j = 0; j < 26; j++){
		if(strchr(encrypt, (temp - j)) == NULL){
			encrypt[i] = toupper(temp - j);
			i++;	
		}
	}
	encrypt[26] = '\0';
}

void initializeDecryptArray(char *encrypt, char *decrypt){
	int i;
	char temp = 'A';
	for(i = 0; i < 26; i++){
		decrypt[encrypt[i] - 'A'] = toupper(temp + i);
	}
	decrypt[26] = '\0';
}

char *removeDuplicates(char *word){
   	int i,j = 0;
	char* str;
	str = malloc(strlen(word));
   	for(i = 0; i < (strlen(word) + 1); i++){
       		if(targetFound(str, strlen(str), word[i]) > -1){
			str[j] = word[i]; 
			j++;	
		}
	}
	str[j] = '\0';
	return str;
}

int targetFound(char *charArray, int num, char target){
	int i;
	for(i = 0; i < num; i++){
		if(strchr(charArray, target) != NULL)
			return -1;
	}
	return 3;
}
void processInput(FILE *inf, FILE *outf, char *substitute){
	char ch;
  	while (fscanf(inf, "%c", &ch) != EOF ){
    	if(isupper(ch))
      		fprintf(outf, "%c", substitute[ch - 'A']);
    	else if(islower(ch))
      		fprintf(outf, "%c", tolower(substitute[ch - 'a']));
    	else
      		fprintf(outf, "%c", ch);
    	}
}
