#include<iostream>
using namespace std;
void myswap(int *,int *);
int main(void){
	int abc[31],tate,yoko;
	cin>>tate>>yoko;
	for(int i=1;i<=tate;i++){
		abc[i]=i;
	}
	int pro1,pro2;
	char doll;
	for(int i=1;i<=yoko;i++){
		cin>>pro1>>doll>>pro2;
		myswap(&abc[pro1],&abc[pro2]);
	}
	for(int i=1;i<=tate;i++){
		cout<<abc[i]<<endl;
	}
	return 0;
}
void myswap(int *a,int *b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}