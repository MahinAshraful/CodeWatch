#include<stdio.h>
int main(void)
{
	int a,s,d,f,g,i;
	s=100000;
	scanf("%d",&a);
	for(i=1;i<=a+1;i++){
	s=s+d;
		d=(s/100)*5;
		if(d%1000!=0){
			g=d/1000;
			d=(g+1)*1000;
		}
	}
	printf("%d\n",s);
	return 0;
}