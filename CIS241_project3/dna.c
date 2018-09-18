#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 5

char* strnsub (char *p, int n);

int main()
{
    char line[] = "His textbook was bought from that bookstore";
    char *p1, *p2;

    p1 = line;

    while (strlen(p1) >= LEN * 2)
    {
        p2 = p1 + LEN;

        while (strlen(p2) >= LEN)
        {
            if(strncmp(p1, p2, LEN) == 0)
            {
                printf("The original string is:\n%s\n", line);
                printf("The first substring:  %s\n", strnsub(p1, LEN));
                printf("The second substring: %s\n", strnsub(p2, LEN));
                return 0;
            }
            *p2++;
        }
        *p1++;
    }
    printf("No repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
    return 0;
}

char* strnsub (char *p, int n)
{
    char *str = (char*)malloc((n-1) * sizeof(char));
    strncpy(str, p, n);
    return str;
}
