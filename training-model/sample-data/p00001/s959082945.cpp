#include <iostream>
#include <algorithm>

using namespace std;
int a(int x,int y){
  return x>y;
}
int main(){
  int list[10];
  for(int i=0;i<10;i++){
    cin >> list[i];
  } 
sort(list,list+10,a);
  
  for(int j=0;j<3;j++){
    cout<< list[j] << endl;
  }
  return 0;
}  