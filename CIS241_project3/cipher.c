#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

int main(int argc, char* argv[])
{
        int choice, key, num;
        char *str = argv[2];
        int len = strlen(argv[2]);
        int key_arr[sizeof(str)/sizeof(str[0])];
        char ch;
        int i, j;
        FILE *fin, *fout;

        if (argc != 5)
        {
                printf ("Usage: cipher option key infile, outfile\n");
                printf ("Option 1 for encryption and 2 for decryption");
                exit(1);
        }
        choice = atoi(argv[1]);  //choice
        char *alpha = "abcdefghijklmnopqrstuvwxyz";  // characters in the alphabt
        for(i = 0; i < len; i++){   //
            for(j = 0; j < 26; j++){
                 if(str[i] = alpha[j])
                      key_arr[i] = j;
               }
       }

               if (choice == 2){
               for(i = 0; i < len; i++)
                   key_arr[i] = -key_arr[i];
               }

           fin = fopen(argv[3], "r");
           fout = fopen(argv[4], "w");

           if (fin ==  NULL || fout == NULL)
               {
                       printf("File could not be opened\n");
                       exit(1);
    }

    while (fscanf(fin, "%c", &ch) != EOF )
    {
    if(isspace(ch))
        num = 0;
    else
        num++;
        fprintf(fout, "%c", encrypt(ch, key_arr[num%len]));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

char encrypt(char ch, int k){
    if (k < 0 )
            k = k + 26;
    if (isupper(ch) )
            return (ch - 'A' + k) % 26 + 'A';
    if (islower(ch) )
            return (ch - 'a' + k) % 26 + 'a';
    return ch;
}
