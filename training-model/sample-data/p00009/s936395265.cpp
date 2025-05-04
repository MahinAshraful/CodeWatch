#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Max=1000007;

bool visit[Max];
int prime[Max];
int num=0;
void init_prim()
{
    memset(visit, true, sizeof(visit));
    for (int i = 2; i <Max; ++i)
    {
        if (visit[i] == true)
        {
            num++;
            prime[num] = i;
        }
        for (int j = 1; ((j <= num) && (i * prime[j] <= 1000000));  ++j)
        {
            visit[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    int n;
    init_prim();
    while(~scanf("%d",&n))
    {
        int l=lower_bound(prime,prime+num,n)-prime;
        if(prime[l]>n)
            l=l-1;
        printf("%d\n",l);
    }
    return 0;
}