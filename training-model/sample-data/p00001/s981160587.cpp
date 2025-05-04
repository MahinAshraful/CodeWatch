#include <iostream>
using namespace std;

int main() {
	int a[10];
	for(int i=0;i<10;i++){
		cin >> a[i];
	}
	for(int i=1;i<10;i++)
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
		for(int k=9;k>=7;k--)	
			cout << a[k] << endl;
	
	return 0;
}