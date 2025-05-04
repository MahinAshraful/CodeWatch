#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	vector<int> num(5);
	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4];
	sort(num.begin(), num.end());
	reverse(num.begin(), num.end());
	printf("%d %d %d %d %d\n", num[0],num[1],num[2],num[3],num[4]);
	return 0;
}