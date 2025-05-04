#include<iostream>

using namespace std;

long long calcGCD(long long a, long long b) {
	long long result = 0;

	while(result == 0) {
		if(a > b){
			a = a % b;
			if (a == 0) {
				result = b;
			}
		}
		else {
			b = b % a;
			if (b == 0) {
				result = a;
			}
		}
	} 
	return result;
}

int main() {
	long long a, b;

	while (cin >> a >> b) {

		long long gcd = calcGCD(a, b);
		long long lcm = a * b / gcd;

		cout << gcd << ' ' << lcm << endl;
	}
	return 0;
}