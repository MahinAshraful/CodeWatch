#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j;
    char ar[120];
    while(gets(ar))
    {
        a=strlen(ar);
        for(i=a-1;i>=0;i--)
        {
            printf("%c",ar[i]);
        }
        printf("\n");
    }
    return 0;
}