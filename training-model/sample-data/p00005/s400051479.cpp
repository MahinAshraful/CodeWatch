#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string.h>
 
using namespace std;

int gcd(int a,int b){
  if(b==0) return a;
  else gcd(b,a%b);
  }
 
int main(){
  
  int a,b;
 
  while(cin>>a>>b){
    
    if(a>=b) cout<<gcd(a,b)<<' '<<a/gcd(a,b)*b<<endl;
    else cout<<gcd(a,b)<<' '<<b/gcd(a,b)*a<<endl;
    
    }
      
}