#include <iostream>
#include <math.h>

using namespace std;

void solve(int a, int b, int c) {
	bool f = false;
	int max_num = max(a, max(b, c));
	int sub1, sub2;
	if (max_num != a) {
		sub1 = a;
		if (max_num != b) sub2 = b;
		else sub2 = c;
	} else if (max_num != b) {
		sub1 = b;
		sub2 = c;
	} 		
	if (pow(max_num, 2) == pow(sub1, 2) + pow(sub2, 2)) f = true;
	if (f) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int num, a, b, c;
	cin >> num;
	for (int i=0; i<num; i++) {
		cin >> a >> b >> c;
		solve(a,b,c);
	}
	return 0;
}