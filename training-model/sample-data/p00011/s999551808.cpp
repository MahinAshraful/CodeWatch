#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int w;
	cin >> w;

	vector<int> a;
	for (int i = 0; i < w; i++)
	{
		a.push_back(i + 1);
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;

		string s;
		cin >> s;

		stringstream ss;
		ss << s;

		ss >> x;
		ss.ignore();
		ss >> y;

		swap(a.at(x - 1), a.at(y - 1));
	}

	for (int i = 0; i < w; i++)
	{
		cout << a.at(i) << endl;
	}
}
