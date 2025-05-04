#include<stdio.h>
int main(){
	double a,b,c,d,e,f,x,y;
	while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f)!=EOF){
		if(a<0){
			a=-a;
			b=-b;
			c=-c;
		}
		if(d<0){
			d=-d;
			e=-e;
			f=-f;
		}
		y=((c*d)-(a*f))/((b*d)-(a*e));
		x=((b*f)-(c*e))/((b*d)-(a*e));
		printf("%.3lf %.3lf\n",x,y);
	}
	return 0;
}