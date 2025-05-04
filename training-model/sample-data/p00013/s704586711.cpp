#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
main(){
	int t[101],co=0;
	for(int i=0;i<=100;++i)t[i]=0;
	while(cin>>t[co]){
		if(t[co]==0){
			--co;
			cout<<t[co]<<endl;
		}else ++co;
	}
}