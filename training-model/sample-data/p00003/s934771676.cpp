#include <iostream>
using namespace std;
int main(){

	int a;
	int b;
	int c;
	int d;

		cin >> d;

		for(int i=1; i<=d; i++){

	cin >> a >> b >> c;

	if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b){

	cout << "YES" << endl;

		}	

	else	{

		cout << "NO" << endl;

		}
	}

	return 0;
}