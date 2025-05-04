#include<iostream>
#include<cmath>
using namespace std;
int gcd(int x,int y){
  if(y>x){
    int t=x;
    x=y;
    y=t;
  }
  while(true){
    int t=y;
    y=x%y;
    x=t;
  
    if(y==0){return x;}
  }
}

int lcm(int x,int y){
  return (double)x/gcd(x,y)*y;//オーバーフロー防止

}


int main(){
  int n,m;
  while(cin>>n>>m){
    cout<<gcd(n,m)<<' '<<lcm(n,m)<<endl;
  }
}