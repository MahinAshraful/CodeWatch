#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	for (int i = 0; i < str.length() / 2; i++) {
		char c;
		c = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = c;
	}

	cout << str << endl;

	return 0;
}