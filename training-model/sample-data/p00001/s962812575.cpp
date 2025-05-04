#include<iostream>
using namespace std;

int main(){
  int num = 10;
  int height[num];

  for(int i=0; i<num; i++)
    cin >> height[i];

  int top3[3]={0,0,0};
  for(int i=0; i<num; i++) {
    for(int j=0; j<3; j++) {
      if(height[i] > top3[j]) {
        for(int k=2; k>j; k--)
          top3[k] = top3[k-1];
        top3[j] = height[i];
        break;
      }
    }
  }

  for(int i=0; i<3; i++)
    cout << top3[i] << endl;

  return 0;
}