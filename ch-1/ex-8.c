#include <stdio.h>

int main()
{
    int c, count;
    count = 0;

    while((c = getchar()) != EOF)
        if(c == '\n' || c == '\t' || c == ' ') 
            count++;

    printf("%d\n", count);
    printf("goodbye\n");
}