#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int a[5];
	for(int i = 0; i < 5; i ++)
		cin >> a[i];
	sort(a, a + 5, greater<int>());
	for(int i = 0; i < 5; i ++)
		cout << a[i] << (i + 1 == 5 ? '\n' : ' ');
	return 0;
}