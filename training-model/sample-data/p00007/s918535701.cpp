#include<iostream>
using namespace std;
#define N 100000
int main(){
	int n,a;
	a=N;
	cin >> n;
	while(n--){
		a+=a/20;
		if(a%1000)a=a-a%1000+1000;
	}
	cout << a <<endl;
	return 0;
}