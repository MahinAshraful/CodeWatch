#include<iostream>
using namespace std;

int main(){

	int a, b, j, tmp, gcd, lcm;
	
	while(cin >> a >> b){
	
		if(a > b){
			tmp = a;
			a = b;
			b = tmp;
		}
	
		gcd = a;
		for(int i=2;; i++){
			if(b % gcd == 0 || gcd == 1) break;
			else{
				for(j=i; a % j != 0; j++);
				gcd = a / j;
			}
		}
		
		lcm = b;
		for(int i=2;; i++){
			if(lcm % a == 0) break;
			else{
				lcm = b * i;
			}
		}
	
		cout << gcd << " " << lcm <<endl;
	
	}

	return 0;
}