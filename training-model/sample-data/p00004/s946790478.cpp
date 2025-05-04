#include<iostream>
#include<cstdio>

using namespace std;

double a,b,c,d,e,f;

int main(){
	while(cin >> a >> b >> c >> d >> e >> f){
		printf("%0.3lf ",(c/a)-((b*c*d-a*b*f)/(a*b*d-a*a*e)));

		printf("%0.3lf\n",(c*d-a*f)/(b*d-a*e));
	}
    return 0;
}