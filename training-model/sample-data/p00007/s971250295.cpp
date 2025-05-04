#include<iostream>
using namespace std;
int main(){
	int n;cin>>n;int C=100;
	for(int i=0;i<n;i++){
		long double E=C;E*=1.05l;
		E+=0.999;C=(int)E;
	}
	cout<<C*1000<<endl;
}