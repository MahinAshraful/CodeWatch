#include <iostream> 
#include<string.h>
#include<stdio.h>
using namespace std;
long long cc( long  long  q, long long  p)
{

	if(q%p==0)
	{
		return p;
	}
	else
	return cc(p,q%p);
}
main()
{
	long long x,y,a[1000],b[1000];
	int i=0;
	while(scanf("%lld%lld",&x,&y)!=EOF)
	{
	  
		 a[i]=cc(x,y);
		 b[i]=x*y/a[i];
	     i++;	
	     
	    
	}
	for(int j=0;j<i;j++)
	{
		printf("%lld %lld\n",a[j],b[j]);
	}
}
