
/* vo00_07.cpp */
#include <iostream>
using namespace std;

int main()
{
	int debt = 100000, n, tmp;

	cin >> n;
	while (n--) {
		debt *= 1.05;
		if (tmp = debt % 1000) { debt += 1000; }
		debt -= tmp;
	}

	cout << (int)debt << '\n';

	return 0;
}