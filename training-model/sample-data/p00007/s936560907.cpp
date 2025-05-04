#include <iostream>
using namespace std;

int round(double num);

int main(){
	int n=100;
	int w;
	cin >> w;

	for(int i=0; i<w; i++){
		n = round(n*1.05);
	}

	cout << n*1000 << endl;

	return 0;
}

int round(double n){
	int m=n;

	if(n>m) return m+1;
	if(n==m) return m;
}