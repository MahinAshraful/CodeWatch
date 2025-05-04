#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <algorithm>
#include <stdio.h>
using namespace std;

bool a[1000000];

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 0 << endl;
		}
		else
		{
			memset(a, false, sizeof(a));

			int cnt = 0;
			for (int i = 2; i <= n; i++)
			{
				if (a[i] == false)
				{
					cnt++;
					for (int j = 1; i * j <= n; j++)
					{
						a[i * j] = true;
					}
				}
			}
			cout << cnt << endl;
		}
	}

	return 0;
}