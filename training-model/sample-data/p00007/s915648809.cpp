#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	long long m=100000,k,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		m=m+(m*5/100);
		if(m%1000!=0)
		{
			m=m/1000;
			m=m*1000+1000;
		}
	}
	cout<<m<<endl;
	return 0;
}