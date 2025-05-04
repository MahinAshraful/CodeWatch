#include<iostream>
#include<cstdio>
#include<utility>
#include<climits>
#include<cmath>
using namespace std;

int main()
{
	int i, j;

	char str[20] = {};
	for (i = 0; cin >> str[i]; i++)
	{}

	for (j = i - 1; j >= 0; j--)
	{
		cout << str[j] ;
	}

	cout << endl;
	return 0;
}