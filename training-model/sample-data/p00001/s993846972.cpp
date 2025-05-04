#include <iostream>
using namespace std;

int main()
{
	int mountain[10] = { 0 };
	int i, j, max, tmp;
	for(i = 0; i < 10; i++)
		cin >> mountain[i];
	for(i = 0; i < 10; i++)
	{
		max = i;
		for(j = i; j < 10; j++)
		{
			if(mountain[j] > mountain[max])
				max = j;
		}
		tmp = mountain[i];
		mountain[i] = mountain[max];
		mountain[max] = tmp;
	}
	for(i = 0; i < 3; i++)
	{
		cout << mountain[i] << endl;
	}
}