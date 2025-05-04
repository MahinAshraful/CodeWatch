#include <stdio.h>
#include <string.h>

int main()
{
   char s[20], r[20];
   int n, c, d;
   gets(s);

   n = strlen(s);

   for (c=n-1,d=0;c>=0;c--,d++)
      r[d] = s[c];

   r[d] = '\0';

   printf("%s\n", r);

   return 0;
}