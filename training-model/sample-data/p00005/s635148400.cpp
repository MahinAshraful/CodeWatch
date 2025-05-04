#include <iostream>

#define CASE double

using namespace std;

int GCD(CASE x, CASE y)
{
	if (x == 0 || y == 0)
		return x + y;
	else
	{
		if (x >= y)
		{
			x = x - y;
			GCD(x, y);
		}
		else
		{
			y = y - x;
			GCD(x, y);
		}
	}
}

int main(){
	CASE a, b;
	unsigned long int d, l;
	while (cin >> a >> b){

		d = (unsigned long int)GCD(a, b);
		l = a * b / d;
		cout << d << " " << l << endl;
	}
	return 0;
}