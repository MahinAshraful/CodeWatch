#include<iostream>
#include<stdio.h>
using namespace std;
main(){
  double a,b,c,d,e,f;
  double x=0,y=0;
  while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f) != EOF){
	y=(c*d-a*f)/(b*d-a*e);
	x=(c-b*y)/a;
	printf("%.3f %.3f\n",x,y);
  }
}