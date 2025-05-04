#include<iostream>
using namespace std;

int main()
{
	int top;
	int a, b, c;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++){

		cin >> a >> b >> c;

		if (a > b)
			top = a;
		else top = b;

		if (c > top)
			top = c;

		if (top == a){
			if ((a * a) == ((b * b) + (c * c)))
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else if (top == b){
			if ((b * b) == ((a * a) + (c * c)))
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else {
			if ((c * c) == ((b * b) + (a * a)))
				cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	return 0;
}