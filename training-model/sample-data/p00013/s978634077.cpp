#include <iostream>
using namespace std;

int main(){
   int a[10] = {}, n, poi;
   while(cin >> n){
     if(n == 0){
       cout << a[9] << endl;
       for(int i = 9;i > 0;--i){
           a[i] = a[i - 1];
          }
     }else{
       for(int i = 0;i < 9;++i){
           a[i] = a[i + 1];
       }
       a[9] = n;
     }
   }
  return 0;
}