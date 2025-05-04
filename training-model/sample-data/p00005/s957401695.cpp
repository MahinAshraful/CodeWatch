#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int gcd2(int a,int b)
{
    while(b!=0)
    {
        int temp=a;
        a=b;
        b=temp%a;
    }
    return a;
}
typedef long long LL;
LL LCM(int a,int b)
{
    int multi=gcd(a,b);
    return (LL)a*(b/multi);
}
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        cout<<gcd(a,b)<<" "<<LCM(a,b)<<endl;
    }
    return 0;
}

