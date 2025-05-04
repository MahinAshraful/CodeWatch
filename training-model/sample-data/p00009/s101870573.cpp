#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
//#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6;

bool vis[maxn];
vector<int> Prms(maxn);

void seive(int n) //sqrt(n)
{
    int m = sqrt(n+0.5);
    for(int i = 2; i <= m; i++){
        if(!vis[i])
        for(int j = i*i; j <= n; j += i){
            vis[j] = true;
        }
    }
    Prms.clear();
    for(int i = 2; i <= n; i++)
        if(!vis[i])
        Prms.push_back(i);
}

//#define LOCAL
int main()
{
#ifdef LOCAL
    freopen("in.txt","r",stdin);
#endif
    seive(maxn);
    int n;
    while(~scanf("%d",&n)){
        int ans = upper_bound(Prms.begin(),Prms.end(),n)-Prms.begin();
        printf("%d\n",ans);
    }
    return 0;
}