#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;



int main(){
    double a,b,c,d,e,f;
    vector<double> tmp(2);
    while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f)!=EOF){
        double x=(c*e-f*b)/(a*e-d*b);
        double y=(c-a*x)/b;
        if(abs(x)<1e-10){
            x=0;
        }
        if(abs(y)<1e-10){
            y=0;
        }
        printf("%.3f %.3f\n",x,y);
    }
    return 0;
}