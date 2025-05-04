#include<iostream>

using namespace std;
bool prime(int x){
	if(x==2)return true;
	if(x==3)return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int main(){
	int data[1000000];
	data[0]=0,data[1]=0;
	for(int i=2;i<1000000;i++){
		if(prime(i))data[i]=data[i-1]+1;
		else data[i]=data[i-1];
	}
	int n;
	while(cin>>n)cout<<data[n]<<endl;
}