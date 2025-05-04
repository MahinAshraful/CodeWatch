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

bool is_prime(int n)
{
	if (n == 2)
	{
		return true;
	}
	else if ((n == 1) || (n % 2 == 0))
	{
		return false;
	}

	int p = (int)sqrt(n);
	for (int i = 3; i <= p; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main()
{
	vector<int> p;
	for (int i = 1; i < 1000000; i++)
	{
		if (is_prime(i))
		{
			p.push_back(i);
		}
	}

	int n;
	for (; cin >> n;)
	{
		int i;
		for (i = 0; i < p.size(); i++)
		{
			if (p.at(i) > n)
			{
				break;
			}
		}

		cout << i << endl;
	}
}
