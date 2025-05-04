#include<iostream>
#include<stdio.h>
using namespace std;

int gcd(int a,int b)
    {
        if(b==0)
            return a;
        else
            gcd(b,a%b);
    }

int main()
{
    int min,max,a,b;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
    max = gcd(a,b);
    min = (a/max)*(b/max)*max;
    cout << max << " " << min<<endl;
    }
    return 0;
}

