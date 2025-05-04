#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int array[5];
	cin >> array[0] >> array[1] >> array[2] >> array[3] >> array[4];
	sort(array, array + 5);
	cout << array[4] << " " << array[3] << " " << array[2] << " " << array[1] << " " << array[0] << endl;
	return 0;
}