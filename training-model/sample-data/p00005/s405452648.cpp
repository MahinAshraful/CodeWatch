#include<iostream>
#include<string>
#include<algorithm>
#include <stdio.h>
using namespace std;


 int euclid(long long int a, long long int b){
  if (b < a) {
    long long int c = b;
    b=a;
    a=c;
  }
  int r=a%b ;
  while(r)
  {
  a=b;
  b=r;
  r=a%b;
  }
return b;
}
int main(){
  long long int a,b;
  while(scanf("%d %d",&a,&b)!=EOF){
    cout << euclid(a,b) << " "<<a*b/(euclid(a,b))<<endl;
}
}

