#include <iostream>
using namespace std;

int main() {
	int h[10];
	int rank[3];
	for(int i = 0; i < 3; i++){
		rank[i] = 0;
	}
	for(int i = 0; i < 10; i++){
		cin >> h[i];
	}
	for(int i = 0; i < 10; i++){
		if(h[i] >= rank[0]){
			rank[2] = rank[1];
			rank[1] = rank[0];
			rank[0] = h[i];
		} else if(h[i] >= rank[1]) {
			rank[2] = rank[1];
			rank[1] = h[i];
		} else if(h[i] >= rank[2]){
			rank[2] = h[i];
		}
	}
	for(int i = 0; i < 3; i++){
		cout << rank[i] << endl;
	}
	return 0;
}