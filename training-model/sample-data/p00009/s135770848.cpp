#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<cmath>
#define mem0(x) memset(x,0,sizeof(x))
#define memff(x) memset(x,0xff,sizeof(x))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define per(i,b,a) for(int i=b;i>a;i--)
#define perr(i,b,a) for(int i=b;i>=a;i--)
#define MAX_N 5050
#define MAX_M 5050
#define MAX_P 1000010
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> P;
map<int,int> m;
const int INF=1<<29;
const int MOD=1e9+7;
int par[MAX_N];
int rank[MAX_N];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
int GCD(int a,int b){if(b==0) return a;return GCD(b,b%a);}
void init(int n){rep(i,0,n){par[i]=i;rank[i]=0;}}
int find(int x){return x==par[x]?x:par[x]=find(par[x]);}
void unite(int x,int y){x=find(x);y=find(y);if(x==y) return;if(rank[x]<rank[y]){par[x]=y;}else{par[y]=x;if(rank[x]==rank[y])rank[x]++;}}
bool same(int x,int y){return find(x)==find(y);}
struct node{int x,y;};
bool cmp(int x,int y){return x>y;}
bool ccmp(node x1,node x2){return x1.x>x2.x;}
LL mod_pow(LL x, LL n,LL mod){LL res=0;while(n>0){if(n&1) res=res*x%mod;x=x*x%mod;n>>=1;}return res;}
int prime[MAX_P];
bool is_prime[MAX_P];
int x;
int sieve(int  n)
{
    int p=0;
    repp(i,0,n)
    {
        is_prime[i]=true;
    }
    is_prime[0]=is_prime[1]=false;
    repp(i,2,n)
    {
        if(is_prime[i])
        {
            prime[p++]=i;
            for(int j=2*i;j<=n;j+=i)
            is_prime[j]=false;
        }
    }
    return p;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(~scanf("%d",&x))
    {
        printf("%d\n",sieve(x));
    }
    return 0;
}