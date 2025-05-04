#include <iostream>
using namespace std;
int main(){
	char t[21];
	char flug=0;
	cin>>t;
	for(int i=20;i>=0;i--){
		if(flug==1){
			cout<<t[i];
		}
		if(t[i]=='\0'){
			flug=1;
		}
	}
	cout<<endl;
	return 0;
}