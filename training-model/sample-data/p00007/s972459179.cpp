#include <iostream>
using namespace std;
int StartDebt = 100000;

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		StartDebt *= 1.05;
		if(StartDebt % 1000 != 0){
			StartDebt = 1000 * (StartDebt / 1000 + 1);
		}
	}
	cout << StartDebt << endl;
	return 0;
}