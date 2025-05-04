#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>
using namespace std;


int main(){
	vector<double> ans_x;
	vector<double> ans_y;
	double a, b, c, d, e, f;
	double tb, tc, te, tf;
	double x, y;
	int i, cnt=0;
	while(cin>>a>>b>>c>>d>>e>>f){
		tb=b*d;
		tc=c*d;
		te=e*a;
		tf=f*a;
		tb-=te;
		tc-=tf;
		y=tc/tb;
		x=(c-b*y)/a;
		ans_x.push_back(x);
		ans_y.push_back(y);
		cnt++;
	}
	for(i=0;i<cnt;i++){
	//	cout.precision(4);
	//	cout.setf(ios::showpoint);
		printf("%.3f %.3f\n",ans_x[i], ans_y[i]);
	}
	return 0;
}