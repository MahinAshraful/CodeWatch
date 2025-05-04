#include<stdio.h>
#include<algorithm>
using namespace std;
int i;
/*int js(long long x,long long y)
{
    for(i=1; ;i++)
    {
        if(i%x==0&&i%y==0)
        {
            break;
        }
    }
    return i;
}*/
main()
{
    long long n,k,j,max,min,x,y,t,a,b;
    while(~scanf("%lld %lld",&x,&y))
    {
        a=x;
        b=y;
       // max=js(x,y);
        if(x>y)
            {
                t=x;
                x=y;
                y=t;
            }
        while(x!=0)
        {
            t=x;
            x=y%x;
            y=t;

        }
        min=y;
        max=a*b/min;
    printf("%lld %lld\n",min,max);
    }

}