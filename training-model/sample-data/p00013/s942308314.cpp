#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int main(){
	stack<int> a;
	int n;

	while (cin >> n) {
		if (n == 0) cout << a.top() << endl, a.pop();
		else a.push(n);
		
	}

	return 0;
}