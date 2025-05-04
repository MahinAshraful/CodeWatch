#include <iostream>

using namespace std;

int main(void)
{
	int input[10];

	for(int i = 0; i < 10; i++){
		cin >> input[i];
	}

	for(int i = 0; i < 3; i++){
		for(int j = i; j < 10; j++){
			if(input[j] > input[i]){
				swap(input[j], input[i]);
			}
		}
	}


	for(int i = 0; i < 3; i++){
		cout << input[i] << endl;
	}


	return 0;
}