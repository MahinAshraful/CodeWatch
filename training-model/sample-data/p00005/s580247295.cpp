#include<iostream>
#include<cstdio>
using namespace std;
long long int sub(long long int x,long long int y);
int sort(long long int *a,long long int *b);
int main(){
long long int a,b,c,x,y;
 while(scanf("%lld %lld",&a,&b)!=EOF){
   c=a*b;
   sort(&a,&b);
   while(1){
     if(a==b)break;
     x=sub(a,b);
     sort(&b,&x);
     a=b;
     b=x;
   }
   y=c/b;
   printf("%lld %lld\n",b,y);
 }
}
long long int sub(long long int x,long long int y){
  return x-y;
}
int sort(long long int *a,long long int *b){
  if(*a<*b){
    long long int temp =*a;
    *a=*b;
    *b=temp;
  }
}