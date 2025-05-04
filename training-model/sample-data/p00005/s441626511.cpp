#include<iostream>
#include<stdio.h>
using namespace std;
unsigned int GCD(unsigned int a,unsigned int b) {
	if(a < b) {
		unsigned int tmp = a;
		a = b;
		b = tmp;
	}
	if(b==0) return a;
	GCD(b,a%b);
}
int main() {
	unsigned int a;
	unsigned int b;
	while(cin >> a >> b) {
		unsigned int gcd = GCD(a,b);
		unsigned int lcm = (a / gcd) * b;
		cout << gcd << " " << lcm << endl;
	}
	return 0;
}