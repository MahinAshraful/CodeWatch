#include<iostream>

using namespace std;

long long HELL(int n){
	if(n==0){return 100000;}
	return ((HELL(n-1)*21/20+999)/1000)*1000;
}

int main(){
	int n;
	cin>>n;
	cout<<HELL(n)<<endl;

	return 0;
}