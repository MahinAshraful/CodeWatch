#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int val[5];
	for(int i=0;i<5;i++)
		cin >> val[i];

	sort(val,val+5);
	for(int i=5;--i;)
		cout << val[i] << " ";
	cout << val[0] << endl;

	return 0;
}