#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
int main(){
  int a,b;
  int temp;
  int i;
  int gcd,lcm;
  int64 A,B;
  while(scanf("%d %d",&a,&b) != EOF){
    A = a;
    B = b;
    while(b != 0){
      temp = a % b;
      a = b;
      b = temp;
    }
    gcd = a;
    lcm = (A * B) / gcd;
    cout << gcd << " " <<  lcm << endl;
  }
}