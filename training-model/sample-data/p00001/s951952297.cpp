#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main(){
	vector<int> height(10);

	for (int i = 0; i < 10; i++)
		cin >> height[i];

	sort(height.begin(), height.end(), greater<int>());
	
	for (int i = 0; i < 3; i++)
		cout << height[i] << endl;
}