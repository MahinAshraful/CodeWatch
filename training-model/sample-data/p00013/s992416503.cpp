#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<iomanip>
#include<list>
#include<math.h>
#include<stack>

using namespace std;


int main(int argc, char **argv)
{
	int n;
	stack<int> rail;
	while (cin >> n) {
		if (n != 0) {
			rail.push(n);
		} else {
			cout << rail.top() << endl;
			rail.pop();
		}
	}
}