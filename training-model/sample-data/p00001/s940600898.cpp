#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int r[10];
	for(int i=0;i<10;i++)
		cin>>r[i];
	sort(r,r+10);
	cout<<r[9]<<endl;
	cout<<r[8]<<endl;
	cout<<r[7]<<endl;
    return 0;
}