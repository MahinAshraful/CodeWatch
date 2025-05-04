#include<stdio.h>
#include<string.h>
int main()
{
    char arr[30];
    int i,s;
    gets(arr);
    s=strlen(arr);
    for(i=s-1;i>=0;i--)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    return 0;
}