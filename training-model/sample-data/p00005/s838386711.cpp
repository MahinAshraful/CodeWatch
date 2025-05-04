#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b){
	if(b==0)return a;
	else gcd(b,a%b);
}
int main(){
	long long int a,b,ans;
	while(cin>>a>>b){
		if(b>a){
			int tmp=a;
			a=b;
			b=tmp;
		}
		cout<<gcd(a,b)<<" "<<a/gcd(a,b)*b<<endl;
	}
    return 0;
}