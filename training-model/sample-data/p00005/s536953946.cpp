#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

long long gcd(long long a,long long b){
	if(b==0) return a;
	else gcd(b,a%b);
}

int main(){
    long long A,B;
	while(cin>>A>>B){
		printf("%lld %lld\n",gcd(A,B),A*B/gcd(A,B));
	}
    return 0;
}