#include<iostream>
using namespace std;
main(){
  int i=0,num,a[10];
  while(cin>>num){
    if(num)a[i++]=num;
    else cout<<a[--i]<<endl;
  } 
}