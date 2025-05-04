#include<iostream>

using namespace std;

int main(){
 int x,buf;
 int H[3];

 for(int i = 0; i < 3; i++){
  H[i] = 0;
 }
 
 for(int i = 0; i < 10; i++){
  cin >> x;
  
  if(x > H[2]){
  
   H[2] = x;
   
   for(int j = 2; j > 0; j--){
  
    if(H[j] > H[j-1]){
     buf = H[j];
     H[j] = H[j-1];
     H[j-1] = buf;
    }
   }
  }
 }
 
 for(int i = 0; i < 3; i++)
    cout << H[i] << endl;
 
  return 0;
}
    