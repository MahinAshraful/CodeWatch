#include<iostream>
using namespace std;
main(){
	int data[5],tmp;
	for(int i=0;i<5;++i)cin>>data[i];
	for(int i=0;i<5;++i){
		for(int j=i;j<5;++j){
			if(data[i]<data[j]){
				tmp=data[i];
				data[i]=data[j];
				data[j]=tmp;
			}
		}
	}
	for(int i=0;i<5;++i){
		if(i<4)cout<<data[i]<<" ";
		else cout<<data[i]<<endl;
	}
}