#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int data[5];
	for(int i=0;i<5;i++)cin>>data[i];
	
	sort(data,data+5,greater<int>());
	for(int i=0;i<4;i++)cout<<data[i]<<" ";
	cout<<data[4]<<endl;
}