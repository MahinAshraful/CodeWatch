#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int hills[10];
	for (int i=0; i<10; i++){
		cin >> hills[i];
	}


	for (int i=9; i>=1; i--){
		for (int j=1; j<10; j++){
			if (hills[j-1] < hills[j]){
				swap(hills[j-1], hills[j]);
			}
		}
	}

	for (int i=0; i<3; i++){
		cout << hills[i] << endl;
	}
	return 0;
}


  