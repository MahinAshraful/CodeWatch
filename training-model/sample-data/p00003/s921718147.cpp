#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int main(){
	double sd[3];
	int N;
	cin>>N;
	while(N>0){
		cin>>sd[0]>>sd[1]>>sd[2];
		sort(sd,sd+3);
		if(sd[2] == sqrt(pow(sd[1],2.0)+pow(sd[0],2.0))){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		N--;
	}
	
	
	return 0;
}