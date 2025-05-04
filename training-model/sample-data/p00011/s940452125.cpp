#include <iostream>
using namespace std;

int main() {
	int w, n, a, b;
	char comma;
	int amida[31];
	for (int i = 1;i < 31;i++) amida[i] = i;
	cin >> w >> n;

	for (int i = 0;i < n;i++) {
		cin >> a >> comma >> b;
		swap(amida[a], amida[b]);
	}

	for (int i = 1;i <= w;i++) {
		cout << amida[i] << endl;
	}

	return 0;
}