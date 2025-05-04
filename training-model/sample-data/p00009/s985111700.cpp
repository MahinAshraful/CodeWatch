#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 999999 + 10;
bool is_prime[maxn];
int tot[maxn];

void sieve(int n){
	fill(is_prime, is_prime + n + 1, true);
	is_prime[0] = is_prime[1] = false;
	
	for(int i=2; i*i <= n; i++) if(is_prime[i])
		for(int j=2*i; j <= n; j+=i)
			is_prime[j] = false;	
}

int main(){
//	freopen("data/in.txt", "r", stdin);
	
	sieve(maxn-1);
	int cnt = 0;
	for(int i=0; i<maxn; i++){
		if(is_prime[i]) cnt++;
		tot[i] = cnt;
	}
	
	int n;
	while(1==scanf("%d", &n)){
		printf("%d\n", tot[n]);
	}

	return 0;
}