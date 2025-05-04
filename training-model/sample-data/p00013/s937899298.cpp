#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

int main() {
	stack<int> a;
	for (int b; cin >> b;) {
		if (b)a.push(b);
		else { cout << a.top() << endl; a.pop(); }
	}
	return 0;
}