#include<iostream>
#include<cstdio>
#include<utility>
#include<climits>
#include<cmath>
using namespace std;

int main()
{
	long a, b;
	long c, d, e;
	long gcd, lcm;


	while (cin >> a >> b)
	{	
		c = a, d = b;
		while (d != 0)
		{
			e = c % d;
			c = d; d = e;
		}

		gcd = c;
		lcm = a * b /gcd;

		cout << gcd << " " << lcm << endl;
	}

	return 0;
}