#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n, ans;
	double debt = 100000;

	cin >> n;

	for(int i = 0; i < n; i++)
	{
		debt = ceil((debt * 1.05) / 1000) * 1000;
	}

	ans = debt;

	cout << ans << endl;

	return 0;
}