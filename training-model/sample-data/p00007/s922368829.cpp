#include "bits/stdc++.h"
using namespace std;

int main(){
	int n;
	cin>>n;
	int ans=100000;
	for(int i=0;i<n;i++){
		ans=(ans*1.05);
		int ans2=ans/1000;
		ans2*=1000;
		if(ans!=ans2){
			ans=ans2+1000;
		}else{
			ans=ans2;
		}
	}
	cout<<ans<<endl;
	return 0;
}