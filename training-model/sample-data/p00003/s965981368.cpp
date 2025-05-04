#include <iostream>
using namespace std;

int triangle(int a,int b,int c){
    //error check
	if(a<=0 || b<=0 || c<=0){
		cout << "ERROR" << endl;
		return 1;
	}
	if(a < b){
		swap(a,b);
	}
	if(a < c){
		swap(a,c);
	}
	
	if(a*a-b*b-c*c == 0){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0; 
}

int main(void){
    int num,x,y,z;
	cin >> num;
	for(int i=0;i<num;i++){
		cin >> x >> y >> z;
		triangle(x,y,z);
	}
}