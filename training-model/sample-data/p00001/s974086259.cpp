#include<iostream>
using namespace std;
int main(){
	int ar[10],r[3],t=10;
	for(int i=0;i<10;i++)
		cin>>ar[i];
	for(int i=0;i<10;i++)
		for(int j=0;j<9;j++)
		if(ar[i]>ar[j]){
			int t;
			t=ar[i];
			ar[i]=ar[j];
			ar[j]=t;
		}
	for(int i=0;i<3;i++)
		cout<<ar[i]<<endl;
	return 0;
}
