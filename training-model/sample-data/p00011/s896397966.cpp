#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int w,n,c,x,y;
	cin>>w>>n;
	int a[w+1]={0};
	for(int i=0;i<=w;i++)a[i]=i;
	for(int i=0;i<n;i++)
	{
		scanf("%d,%d",&x,&y);
		c=a[x],a[x]=a[y],a[y]=c;
	}
	for(int i=1;i<=w;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}