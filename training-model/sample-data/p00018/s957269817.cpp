#include <algorithm>
#include <iostream>
using namespace std;

int main(){
	int a[5],i;
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]){
		sort(a,a+5,greater<int>());
		i=0;
		for(int i=0;i<5;i++){
			cout << a[i];
			if(i!=4)cout << " ";
			else cout << endl;
		}
	}
}