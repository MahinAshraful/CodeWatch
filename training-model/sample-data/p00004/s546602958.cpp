#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
#include<set>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

int main(){
	double a,b,c,d,e,f;
	while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF){
		
		if(d==0){
			swap(a,d);
			swap(b,e);
			swap(c,f);
		}
		
		double y;
		if(a==0){
			y = c/b;
		}else{
			double A = b/a-e/d;
			double B = c/a-f/d;
			
			y = B/A;
		}
		double x = f/d-e/d*y;
		
		if(x==fabs(x))x=fabs(x);
		if(y==fabs(y))y=fabs(y);
		
		printf("%.3lf %.3lf\n",x,y);
	}
}