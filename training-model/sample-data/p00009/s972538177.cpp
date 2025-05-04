#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<list>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>

using namespace std;

#define MAX_N 1000005
const int INF = 0x3f3f3f3f;

int prime[1000000];
int c[MAX_N];

void Prime_creat()
{
    int i,j;
    for(i=2; i<=1000000; i++)
    {
        if(prime[i])
        {
            c[i] = c[i - 1] + 1;
            for(j=i+i; j<=1000000; j+=i)
                prime[j]=0;
        }
        else
        {
            c[i] = c[i - 1];
        }
    }
}

int main()
{
    memset(prime, 1, sizeof(prime));
    Prime_creat();
    int n;

    while(~scanf("%d", &n))
    {
        printf("%d\n", c[n]);
    }

    return 0;
}