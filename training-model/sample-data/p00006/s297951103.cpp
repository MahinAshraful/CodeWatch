#include <stdio.h>
#include <string.h>

int main(void) {
  char s[100] = {0};
  int i = 0;
  gets(s);
  i = strlen(s)-1;
  while(i >= 0)
  putchar(s[i--]);
  
  putchar('\n');
  return 0;
}