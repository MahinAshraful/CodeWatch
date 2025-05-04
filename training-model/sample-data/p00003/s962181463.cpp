#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> a(3);
		for (int j = 0; j < a.size(); j++)
		{
			cin >> a.at(j);
		}
		sort(a.begin(), a.end());

		cout << (a.at(0)*a.at(0) + a.at(1)*a.at(1) == a.at(2)*a.at(2) ? "YES" : "NO") << endl;
	}
}
