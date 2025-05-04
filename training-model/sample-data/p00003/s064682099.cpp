#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		array<int, 3> edge;
		for (int i = 0; i < 3; i++){
			cin >> edge[i];
		}
		sort(edge.begin(), edge.end());
		if (pow(edge[0], 2) + pow(edge[1], 2) == pow(edge[2], 2)){
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}