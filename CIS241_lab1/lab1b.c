#include <stdio.h>
#include <ctype.h>

int main () {
char ch[300];
int symbol = 0, words = 0, punct = 0;
int i;

printf("Enter text (Ctrl-D to quit). \n");
scanf("%[^\n]s", &ch);    // found this on stack overflow
for(i = 0; ch[i] != '\0'; i++){
    if(isspace(ch[i]))  // checks for a space
        words++;
    if(ispunct(ch[i]))  // checks for punctuation
        if(ch[i] != punct){ //if statement to create
            punct = ch[i];  // sequence
            symbol++;
        }
}
printf("Words: %d \n", words + 1);
printf("Symbol sequences: %d \n", symbol);
}
