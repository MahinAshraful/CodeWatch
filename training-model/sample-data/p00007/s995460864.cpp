#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a = 0; int b = 100000;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		b += (b / 20);
		while (b % 1000 != 0)
		{
			b++;
		}
	}
	cout << b << endl;

	return 0;
}