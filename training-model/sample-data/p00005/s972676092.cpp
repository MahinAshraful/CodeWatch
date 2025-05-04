#include<bits/stdc++.h>
/*
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
*/
using namespace std;

typedef long long ll;

#define sqr(x) (x)*(x)
#define pb push_back
#define fst first
#define snd second

const ll mod=1000000007;
const int maxn=100005,maxm=505;
const double eps=1e-9;
const double pi=acos(-1.0);

ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

ll a,b;

int main()
{
	int i,j,T;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		ll g=gcd(a,b);
		printf("%lld %lld\n",g,a/g*b);
	}
	return 0;
}