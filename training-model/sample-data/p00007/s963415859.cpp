#include <iostream>
using namespace std;

int main() {
	int weeks, debt = 100000;

	cin >> weeks;
	for (int i = 0;i < weeks;i++) {
		debt *= 1.05;
		if (debt % 1000 != 0) debt = 1000 * (debt / 1000 + 1);
	}
	cout << debt << endl;
	return 0;
}