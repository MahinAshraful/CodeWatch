#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	int numbers[5];
	for(auto& n : numbers)
		cin >> n;

	sort(numbers, numbers+5, greater<int>());

	cout << numbers[0] << ' '
		 << numbers[1] << ' '
		 << numbers[2] << ' '
		 << numbers[3] << ' '
		 << numbers[4] << endl;
	
	return 0;
}