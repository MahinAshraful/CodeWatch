#include<iostream>

using namespace std;

int main() {
	int result = 100000;
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		result += (result * 5) / 100;
		if (result % 1000) {
			result -= result % 1000;
			result += 1000;
		}
	}

	cout << result << endl;
	return 0;
}