#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
      return a;
   gcd(b,a%b);
}

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
         int k=gcd(a,b);
         int m=a/k*b;
         cout<<k<<" "<<m<<endl;
   }
 return 0;
}