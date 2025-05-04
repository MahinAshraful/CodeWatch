#include<iostream>

using namespace std;

int main(void){
	
	int n;
	while(cin >> n){
		long money = 100000;
		for(int i = 0; i < n; i++){
			money *= 1.05;
			if(money % 1000) money = money - (money%1000) + 1000;
		}
		cout << money << endl;
	}
	return 0;
}