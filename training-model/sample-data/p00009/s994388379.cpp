#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long int lnt;
typedef pair<lnt,lnt> P;
bool isprime[1000000];
vector<lnt> primes;

int main()
{
	fill(isprime,isprime+1000000,1);
	isprime[0]=isprime[1]=0;
	for(lnt i=2;i<1000000;i++){
		if(!isprime[i]) continue;
		primes.push_back(i);
		for(lnt j=2*i;j<1000000;j+=i) isprime[j]=0;
	}
	lnt n;
	while(scanf("%lld",&n)!=EOF){
		cout<<upper_bound(primes.begin(),primes.end(),n)-primes.begin()<<endl;
	}
}