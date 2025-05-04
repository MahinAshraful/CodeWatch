#include<stdio.h>
#include<string.h>
int main() {
   char r[20],temp;
   int i,j=0;
   gets(r);
   i = 0;
   j = strlen(r) - 1;
   while (i < j) {
      temp= r[i];
      r[i]=r[j];
      r[j]=temp;
      i++;
      j--;
   }
   printf("%s\n",r);
   return (0);
}