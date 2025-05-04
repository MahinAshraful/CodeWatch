#include<iostream>
using namespace std;
#define N 11
int push();
int pop();
 int top=0;
  int buffer[N];
  int num;
  int out[N];
  int status;


int main(void){
 
  while(1){
    
    status = scanf("%d", &num);
    if(status == EOF)break;
    if(num != 0)push();
    else if(num == 0){
      cout << pop() << endl;
    }
  }
  
  
  return 0;
}

int push(){
  
  top++;
  buffer[top]=num;
}

int pop(){
  int x=buffer[top];
  top--;
  return x;
}