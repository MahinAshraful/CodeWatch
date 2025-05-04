#include <stdio.h>
#include <string.h>

int main(){
  char str[30];
  int len, i;

  scanf("%[^\n]", str);
  len=strlen(str);
  for(i=0; i<len; i++){
    putchar(str[len-i-1]);
  }
  putchar('\n');
  return 0;
}