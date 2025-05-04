#include <iostream>
using namespace std;

int main(){
	int n;
	int money = 100000;
	cin >> n;

	for(int i=0 ; i < n ; i++) {
		money *=1.05;
		if (money % 1000 != 0)
			money = money - money % 1000 + 1000;
	}
		cout << money << "\n";

}