#include<stdio.h>
int main()
{
int n,x;

double r,y;
x=100000;
r=1.05;
scanf("%d",&n);
for(int i=0;i<n;i++){
x=r*x;
if(x%1000>0)x=x+1000-(x%1000);
}
printf("%d\n",x);
return 0;
}