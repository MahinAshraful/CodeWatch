#include <cstdio>
#include <iostream>

using namespace std;


int main(){

	int w[31];
	
	int n,m;
	int a,b;

	for(int i=0;i<31;i++)w[i]=i;

	cin>>n>>m;

	for(int i=0;i<m;i++){
		scanf("%d,%d",&a,&b);
		int temp=w[a];
		w[a]=w[b];
		w[b]=temp;
	}
	for(int i=1;i<=n;i++)cout<<w[i]<<endl;


	return 0;
}