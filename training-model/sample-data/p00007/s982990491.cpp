#include <iostream>

using namespace std;

int main()
{

	int n;
	cin >> n;

	int d = 100000;

	for (int i = 0; i < n; ++i)
	{
		d = static_cast <int> (static_cast <double> (d) * 1.05);
		if (d % 1000 > 0)
		{
			d = d - (d % 1000) + 1000;
		}
	}

	cout << d << endl;

	return 0;
}