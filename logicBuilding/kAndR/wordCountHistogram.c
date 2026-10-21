#include <stdio.h>
#define IN 1
#define OUT 0

int main()
{   
    int c;
    int STATE = OUT;
    int nc, nl, wc;
    nc = nl = wc = 0;
    while ((c = getchar()) != EOF) {
      ++nc;

      if (c == '\n') {
        ++nl;  
      }
      
      if (c == ' ' || c == '\t' || c == '\n') {
        if (STATE == IN) {
          printf("\n");
        }
        STATE = OUT;

      } else if (STATE == OUT) {
        STATE = IN;
        wc++;
      }

      if (STATE == IN) {
        printf("==");
      }
    }

    printf("line count %d , char count %d word count %d \n", nl, nc, wc);
}