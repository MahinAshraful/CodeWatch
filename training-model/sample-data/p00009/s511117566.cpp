#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)



const int PS = 1000000;
int prime[PS];
int set_prime(){
	rep(i,PS)prime[i]=1;
	prime[0]=prime[1]=0;
	rep(i,PS){
		if(prime[i]==0)continue;
		for(int j=i*2;j<PS;j+=i)prime[j]=0;
	}
}


int sum[PS];
int set_sum(){
	set_prime();
	rep(i,PS)sum[i]=0;
	reps(i,1,PS)sum[i]=sum[i-1]+prime[i];
}
int main(){
	set_sum();
	
	int a;
	while(scanf("%d",&a)!=EOF){
		printf("%d\n",sum[a]);
	}
}