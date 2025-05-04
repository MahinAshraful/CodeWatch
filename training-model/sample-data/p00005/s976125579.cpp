#include <iostream>
using namespace std;

long long int gcd(long long int m,long long int n)
{
	if (n == 0)
		return m;
	return gcd(n,m % n);
}

int main()
{
	long long int a, b;
	while (cin >> a >> b)
		cout << gcd(a, b) << " " << a * b / gcd(a, b) << endl;
	return 0;
}