#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> h(10);
	for (int i = 0; i < 10; ++i) cin >> h[i];

	sort( h.begin(), h.end(), greater<int>() );

	cout << h[0] << endl;
	cout << h[1] << endl;
	cout << h[2] << endl;
}