#include <iostream>

using namespace std;

int main()
{
	char sr[20];
	cin >> sr;
	for (int i = 20; i >0; i--)
	{
		if (sr[i - 1] != '\0') {
			cout << sr[i - 1];
		}
	}cout << endl;
	return 0;
}