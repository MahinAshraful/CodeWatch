#include <iostream>

using namespace std;

int main()
{
	int loan = 100000;
	int n;
	
	cin >> n;
	for (int i = 0; i < n; i++){
		loan *= 1.05;
		if (loan % 1000 != 0){
			loan += 1000 - (loan % 1000);
		}
	}
	cout << loan << endl;
	return (0);
}