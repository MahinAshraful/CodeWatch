#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const* argv[])
{
	int n{};
	int lent{100000};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		lent += lent * 0.05;
		if (lent % 1000) {
			lent = (lent / 1000) * 1000;
			lent += 1000;
		}
	}
	cout << lent << std::endl;
	return 0;
}