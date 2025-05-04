#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>


using namespace std;

int main() {
	
	vector<int> v;
	v.resize(5);
	for(int i = 0; i < 5; i++) {
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	for(int i = 0; i < 4; i++) {
		cout << v[i] << " ";
	}
	cout << v[4];
	
	cout << endl;
	
	return 0;
}