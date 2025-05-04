#include<iostream>
using namespace std;

long long GCD(unsigned long long a,unsigned long long b){
	if(b==0)return a;
	unsigned long long alt=a%b;
	GCD(b,alt);
}

int main(){
	unsigned long long a,b;
	while(cin>>a){
		cin>>b;
		unsigned long long ansGCD=GCD(a,b);
		cout<<ansGCD<<" "<<a*b/ansGCD<<endl;
	}
	return 0;
}