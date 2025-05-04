#include<stdio.h>
#include<algorithm>
using namespace std;

int a[5]={0};
int b[4]={0};
int hit=0,blow=0;

int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a,a+5);
    for(int i=4;i>=0;i--)
    {
        printf("%d",a[i]);
        if(i!=0)
        {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}