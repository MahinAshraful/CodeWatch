#include<iostream>
#include<string.h>

using namespace std;

int main(){
	char str[25];
	int i, num;
	
	cin >> str;

	num = strlen(str);

	for(i = num-1; i >= 0; i--){
		cout << str[i];
	}
	cout << endl;
}