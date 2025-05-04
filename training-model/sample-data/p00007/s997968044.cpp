#include<iostream>
using namespace std;

int main(){

	int n, ans = 100000;
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		ans *= 1.05;
		ans = 1000 * (ans / 1000 + (ans % 1000 != 0));
	}
	
	cout << ans << endl;

    return 0;
}