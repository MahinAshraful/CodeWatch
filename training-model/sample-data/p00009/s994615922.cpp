#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;

int prime[1000000];
bool is_prime[1000000];
int seive(int n){
	int p=0;
	for(int i=0;i<=n;i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i){
				is_prime[j]=false;
			}
		}
	}
	return p;
}
//??¨????????????????????????
int main() {
	int n;
	while(cin>>n){
		cout<<seive(n)<<endl;
	}
}