#include<cstdio>

int main(){
	long long a,b,g,l,t;
	while(scanf("%d %d", &a, &b) + 1){
		if(a > b){
			t = a;
			a = b;
			b = t;
		}
		if(b % a){
			t = a / 2;
			for(int i = t; i > 0; i--){
				if(!(a % i)){
					if(!(b % i)){
						g = i;
						i -= t;
						printf("%lld %lld\n", g, a * b / g);
					}
				}
			}
		}else{
			printf("%lld %lld\n", a, b);
		}
	}
	return 0;
}