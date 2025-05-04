#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

#define N 100000;

int main()
{
	int n;
	int a;
	a = N;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		a *= 1.05;
	if(a % 1000 != 0){
		a += 1000 - (a % 1000);
	}
}
	cout << a << endl;
}