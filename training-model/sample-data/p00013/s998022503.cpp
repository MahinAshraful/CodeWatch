#include <iostream>
  
struct Stack{
  int data[100000];
  int idx;
  Stack():idx(0){}
  void push(int val){ data[idx++]=val;}
  int pop(){ return data[--idx];}
};

int main(){
  Stack s;
  int val;
  while(std::cin>>val){
    if(val==0)
      std::cout<<s.pop()<<std::endl;
    else
      s.push(val);
  }
  return 0;
}