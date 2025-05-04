#include<cstdio>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        int d=gcd(a,b);
        int lc=a/d*b;
        printf("%d %d\n",d,lc);
    }
}