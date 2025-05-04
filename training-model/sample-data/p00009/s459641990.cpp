#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int prime[1000000];
int Prime_creat()
{
    int i,j;
    for(i=2;i<=1000000;i++)
    {
        if(prime[i])
        {
            for(j=i+i;j<=1000000;j+=i)
            prime[j]=0;
        }
    }
}
int main()
{
    int i,n,ans;
    memset(prime,1,sizeof(prime));//  1是素数 0不是素数
    Prime_creat();
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(i=2;i<=n;i++)
        {
            if(prime[i])
            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}