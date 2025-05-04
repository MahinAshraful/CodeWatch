#include<iostream>
using namespace std;
int increase_debt(int debt,int n) {
	if(n==0) return debt;
	debt += debt*0.05;
	if(debt % 1000 != 0)
		debt += 1000 - debt % 1000;
	increase_debt(debt,n-1);
}
int main() {
	int n;
	cin >> n;
	cout << increase_debt(100000,n) << endl;
	return 0;
}