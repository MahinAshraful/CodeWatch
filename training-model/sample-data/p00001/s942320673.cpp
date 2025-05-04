#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int height, list[10];

  for(int i=0; i<10; i++){
    cin >> height;
    list[i] = height;
  }

  for(int i=0; i<9; i++){
    for(int j=9; j>i; j--){
      if(list[j]>list[j-1]){
	swap(list[j], list[j-1]);
      }
    }
  }

  for(int i=0; i<3; i++){
    cout<<list[i]<<endl;
  }
}