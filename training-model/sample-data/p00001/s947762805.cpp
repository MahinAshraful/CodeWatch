#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

main()
{
    int height[10];
    int i,j;

    for(i=0;i<10;i++)
    {
        scanf("%d",&height[i]);
    }
    sort(height, height+10);

    for(j=0;j<3;j++)
    {
        printf("%d\n",height[9-j]);
    }
    return 0;
}