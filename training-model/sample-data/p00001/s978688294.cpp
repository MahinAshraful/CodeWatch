#include<iostream>

using namespace std;

//??\?????????
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int str,mt[10];
	int i;
	
	for(i=0;i<10;i++){
		cin >> str;
		mt[i] = str;
	}
	
	// sort
	int num = 1;
	while(num<=3){
		str = mt[num-1];
		for(i=num;i<10;i++){
			if(str<mt[i]){
				str = mt[i];
				swap(mt[num-1],mt[i]);
			}
		}
		cout << mt[num-1] << "\n";
		num++;
	}
	
	return 0;
}