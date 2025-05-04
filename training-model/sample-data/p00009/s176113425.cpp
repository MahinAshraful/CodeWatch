#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	long long int n;
	while (cin >> n) {
		int m = 0;
		long long int prime[2000000];
		bool is_prime[2000000];
		for (int i = 0; i <= n; i++) {
			is_prime[i] = true;
		}
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i <= n; i++) {
			if (is_prime[i]) {
				m++;
				for (int j = i * 2; j <= n; j += i) {
					is_prime[j] = false;
				}
			}
		}
		cout << m << endl;
	}
	return 0;
}