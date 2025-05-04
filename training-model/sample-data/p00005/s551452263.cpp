#include <cstdio>

long long int gcd(long long int a,long long int b){
	if(b==0) return a;
	gcd(b,a%b);
}

int main(){
	long long int a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
	    long long int c=gcd(a,b);
	    long long int d=a*b/c;
	    printf("%lld %lld\n",c,d);
	}
	return 0;
}