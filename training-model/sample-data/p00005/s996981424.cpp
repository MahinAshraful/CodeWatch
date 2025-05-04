#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (l);i < (r);i++)
#define ALL(x) (x).begin(),(x).end()
template<typename T> bool chmax(T& a,const T& b){return a < b ? (a = b,true) : false;}
template<typename T> bool chmin(T& a,const T& b){return b < a ? (a = b,true) : false;}
typedef long long ll;

long long gcd(long long x,long long y)
{
	return y ? gcd(y,x % y) : x;
}

long long lcm(long long x,long long y)
{
	return x / gcd(x,y) * y;
}

ll A,B;

int main()
{
	while(~scanf("%lld%lld",&A,&B)){
		printf("%lld %lld\n",gcd(A,B),lcm(A,B));
	}

	return 0;
}