#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(){
	string code;
	string train;
	int i,j;

	while(cin >> code){
		if(code == "10") code = 'A';

		if(code == "0"){
			if(train[train.size()-1] == 'A'){
				cout << "10" << endl;
			}else{
				cout << train[train.size()-1] << endl;
			}
			string temp;
			for(i=0 ; i<train.size()-1 ; i++){
				temp += train[i];
			}
			train = temp;
		}else{
			train += code;
		}
	}

} 