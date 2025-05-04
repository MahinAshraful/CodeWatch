#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main(){
  int train[10],n,i;
  n = 0;
  int order[100],intrain[10];
  for( i = 1;i <= 10;i++){
    train[i] = i;
  }
  for(i=0;i<100;i++)
    order[i] = 11;
  i = 0;
  while(scanf("%d",&order[i]) != EOF){i++;}
  for(i = 0;order[i] != 11;i++){
    if(order[i] != 0){
      intrain[n] = order[i]; n++;}else if(order[i] == 0){
      n--;      cout << intrain[n] << endl;}
  }
}
 