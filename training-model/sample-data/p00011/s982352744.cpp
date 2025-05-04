#include <iostream>
using namespace std;

int main()
{
	int w, n;
	cin >> w;
	int* num = new int[w];
	for (int i = 0; i < w; i++) {
		num[i] = i + 1;
	}
	for (cin >> n; n--;) {
		int a, b;
		char c;
		cin >> a >> c >> b;
		int tmp = num[a - 1];
		num[a - 1] = num[b - 1];
		num[b - 1] = tmp;
	}
	for (int i = 0; i < w; i++) {
		cout << num[i] << endl;
	}
	return 0;
}