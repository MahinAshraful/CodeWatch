#include <stdio.h>
#include <string.h>
 
int main(void)
{
  char str[25] = {0};
  int cx;

  fgets(str, sizeof(str), stdin);
  cx = strlen(str);

  for (int x=cx-2; x>=0; x--) {
    putchar(str[x]);
  }
  puts("");
 
  return 0;
}