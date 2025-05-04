#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector> 
#include<limits>
#include<numeric>
#include<math.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define in(x) cin >> x
#define out(str) cout << str << endl

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

float a,b,c,d,e,f,x,y;

int main(){
    while(cin>>a>>b>>c>>d>>e>>f){
        if(a==0){
            y=b/c;
            x=(f-e*y)/d;
        }
        else{
            y=(c*d/a-f)/(b*d/a-e);
            x=(c-b*y)/a;
        }
        printf("%.3f %.3f\n",x,y);
    }
}


