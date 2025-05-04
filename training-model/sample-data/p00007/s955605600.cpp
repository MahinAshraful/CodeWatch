#include <iostream>

using namespace std;
int main() {
	int n, total;
	total = 100000;
	cin >> n;
	for(int i = 0; i < n; i++) {
		total *= 1.05;
		if(total % 1000 != 0) {
			total = total - total % 1000;
			total += 1000;
		}
	}
	cout << total << endl;

	return 0;
}