#include <math.h>
#include <iostream>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <string>

#define YES "YES"
#define NO "NO"
#define space ' '

using namespace std;

void init();
void func();

int main(void)
{
	
	func();

	return 0;
}


#define MAXIMUM 1000000
bool table[MAXIMUM];
int cnt[MAXIMUM];
bool non = true;
bool prime = false;

void init()
{
		table[0] = non;
	table[1] = non;
	for (int i = 2; i < MAXIMUM; i++)
	{
		if (table[i] == prime)
		{
			for (int j = i * 2; j < MAXIMUM; j += i)
			{
				table[j] = non;
			}
		}
	}
	for (int i = 1; i < MAXIMUM; i++)
	{
		if (table[i] == prime)
		{
			cnt[i] = cnt[i - 1] + 1;
		}
		else
		{
			cnt[i] = cnt[i - 1];
		}
	}

}

void func()
{
	
	int n;

	init();

	while (cin >> n, !cin.eof())
	{
		cout << cnt[n] << endl;
	}

}