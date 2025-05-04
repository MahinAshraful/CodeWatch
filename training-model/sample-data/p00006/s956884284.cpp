#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string.h>
#include <deque>
#define REP(i,j,n) for(int i=j;i<n;i++)
#define SORT(x) sort(x.begin(),x.end())

using namespace std;



int main() {
	string s;
	char v[20];
	/*getline(cin,s);

	for (auto itr = s.end(); itr != s.begin(); itr--) {
		cout << *itr;
	}
	cout << endl;*/

	cin >> v;
	for (int i = strlen(v)-1; i > -1; i--) {
		cout << v[i];
	}
	cout << endl;
	return 0;
}