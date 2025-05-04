#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int H[10];
int main() {
	for (int i = 0; i < 10; i++) {
		cin >> H[i];
	}
	sort(H, H+10,greater<int>());
	for (int i = 0; i <3 ; i++) {
		cout << H[i] << endl;
	}
}