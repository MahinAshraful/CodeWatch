#include<iostream>
using namespace std;
int main() {
	int x[3];
	int a,b;
	cin >> b;
	for(a=0;a<b;a++) {
		cin >> x[0] >> x[1] >> x[2];
		if(x[0]*x[0] + x[1]*x[1] == x[2]*x[2]){
			cout << "YES" << endl;
		}
		else if(x[0]*x[0] + x[2]*x[2] == x[1]*x[1]){
			cout << "YES" << endl;
		}
		else if(x[1]*x[1] + x[2]*x[2] == x[0]*x[0]){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	return 0;
}