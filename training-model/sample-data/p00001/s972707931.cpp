#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;

int main() {
	int i, j, a[10] = {0}, temp;
	for (i = 0; i < 10; i++) {
		cin >> a[i];
	}
	for (i = 0; i < 9; i++) {
		for(j = i + 1; j < 10; j++) {
			if (a[j] < a[i]) {
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	for (i = 9; i > 6; i--) {
		cout << a[i] << endl;
	}
	return 0;
}