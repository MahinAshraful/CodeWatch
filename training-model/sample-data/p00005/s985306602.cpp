#include <cstdio>
using namespace std;

int Euc(int a, int b){
	int c;
	while(a % b != 0){
		c = b;
		b = a % b;
		a = c;
	}
	
	return b;
}

int main(){
	int a, b;
	int gcd, lcm;
	int sub;
	
	while((scanf("%d", &a)) != EOF){
		scanf("%d", &b);
		
		if(a < b){
			sub = a;
			a = b;
			b = sub;
		}
		
		gcd = Euc(a, b);
		lcm = (a / gcd) * b;
		
		printf("%d %d\n", gcd, lcm);
	}
	
	return 0;
}