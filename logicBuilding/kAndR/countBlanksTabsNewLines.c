#include <stdio.h>

int main()
{
    int blankcount = 0, tabcount = 0, lc = 0;
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            blankcount++;
        
        if(c == '\t')
            tabcount++;

        if(c == '\n')
            lc++;
    }

    printf("blank spaces count : %d\n",blankcount);
    printf("tab count : %d\n",tabcount);
    printf("line count : %d\n",lc);
    printf("EOF : %d\n",EOF);
}