#include <stdio.h>

int main() {
  int c; 
  int digits[10];
  int wspace = 0;
  int others = 0;


  for (int i = 0; i < 10; i++) {
    digits[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      wspace++;
    } else if (c >= '0' && c <= '9') {
      digits[c - '0']++;
    } else {
      others++;
    }
    putchar(c);
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", digits[i]);
  }

  printf("  Whitespace: %d, other: %d\n", wspace, others);
  return 0;
}