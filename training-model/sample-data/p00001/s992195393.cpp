# include "iostream"
using namespace std;

int main()
{
	int a[10];
	int i, j;

	for (i = 0; i < 10; i++)
		cin >> a[i];

	for (i = 1; i < 10; i++)
		for (j = 0; j < 10 - i; j++)
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);

			cout << a[9] << endl << a[8] << endl << a[7] << endl;


	return 0;
}