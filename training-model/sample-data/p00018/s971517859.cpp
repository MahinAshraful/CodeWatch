#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

int main(){
	int a[5];
	int i, j, temp = 0;
	for(i = 0;i < 5;i++){
		cin >> a[i];
	}

	for(i = 0;i < 5;i++){
		for(j = i+1;j < 5;j++){
			if(a[i] < a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			
		}
	}

	for(i = 0;i < 5;i++){
		if(i == 0){
			cout << a[i];
		}
		else{
			cout << " " << a[i];
		}
	}
	cout << endl;


	return 0;
}