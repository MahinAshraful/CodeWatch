#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c,d,e,f;
	while( cin >> a >> b >> c >> d >> e >> f){
		double s = a * e - b * d;
		double x = e * c + -b * f;
		double y = -d * c + a *f;
		
		printf("%.3lf %.3lf\n",x/s+1e-9,y/s+1e-9);
	}
}