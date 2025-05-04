#include<iostream>

using namespace std;

#define size 5

main(){

  int data[5];


  cin >> data[0] >> data[1] >> data[2] >> data[3] >> data[4] ;

  for(int front = 0;front <size-1;front++){
    int minIndex = front;
    for(int j = front+1;j<size;j++){
      if(data[j]<data[minIndex])minIndex=j;
    }
    
    int temp = data[front];
    data[front]=data[minIndex];
    data[minIndex]=temp;
  }

  cout << data[4]<<" "<< data[3]<<" "<< data[2]<<" "<< data[1]<<" "<< data[0]<<endl;
  return 0;
}