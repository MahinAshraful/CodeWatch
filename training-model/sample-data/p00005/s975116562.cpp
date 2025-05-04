#include<cstdio>
#include<algorithm>

using namespace std;
#define lli unsigned long long int

lli gcd(lli a,lli b){
  lli c;
  while(a!=0){
    c=a; a=b%a; b=c;
  }
  return b;
}


int main(){
  lli a,b;
  while(~scanf("%lld%lld",&a,&b)){
          
    lli tmp1=gcd(a,b);
    lli tmp2=a*b/tmp1;
    printf("%lld %lld\n",tmp1,tmp2);

  }
  return 0;
}