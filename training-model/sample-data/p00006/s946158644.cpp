#include <iostream>
#include <string>

using namespace std;

string reverse(string s)
{
	char *rev_c = new char[s.size()];
	for (int i = s.size() - 1; i >= 0; i--)
	{
		rev_c[s.size() - 1 - i] = s[i];
 	}
	string rev_s(rev_c, s.size());
	delete rev_c;
	return rev_s;
}

int main()
{
	string s;
	cin >> s;
	cout << reverse(s) << endl;
	return 0;
}
