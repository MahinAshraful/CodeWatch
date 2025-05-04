#include<iostream>
using std::cin;
using std::cout;
using std::endl ;
int main()
{
	int b[10];
	int i=0,j;
	for(;i<10;i++)
		cin>>b[i];
	int t;
	for(i=0;i<3;i++)
	{
		for(j=0;j+i<9;j++)
			while(b[j]>b[j+1])
			{	t=b[j];b[j]=b[j+1];b[j+1]=t;}
		cout<<b[j]<<endl;
	}
	return 0;
}