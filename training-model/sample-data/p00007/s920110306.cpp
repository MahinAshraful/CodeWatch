#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	long s = 100000;
	for (int i = 0; i<n; i++) {
		s = s * 1.05;
		int s1 = s % 1000;
		if (s1 != 0) {
			s = s - s1 + 1000;
		}
	}
	cout << s << "\n";
	return 0;
}