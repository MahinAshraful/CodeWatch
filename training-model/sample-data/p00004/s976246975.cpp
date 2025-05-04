#include <stdio.h>

int main(){
	double a,b,c,d,e,f;
	double x,y;
	while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f)!=EOF){
	x=(c*e-f*b)/(a*e-d*b);
	y=(a*f-d*c)/(a*e-b*d);
	x=x*1000;
	if(x>0) x=(double)(int)(x+0.5);
	else  x=(double)(int)(x-0.5);
	x=x/1000;
	y= y*1000;
	if(y>0) y=(double)(int)(y+0.5);
	else y=(double)(int)(y-0.5);
	y=y/1000;
	printf("%.3f %.3f\n",x,y);
	}
	return 0;
}