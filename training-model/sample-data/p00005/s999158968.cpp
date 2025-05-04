#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long int find_GCD(long long int a, long long int b){
  long long int max = 0;
  for(int i=min(a, b);i>0;i--){
    if(a%i==0 && b%i==0){
      max = i;
      break;
    }
  }
  return max;
}

long long int find_LCM(long long int a, long long int b){
  long long int LCM;
  for(int i=max(a, b);i<=a*b;i+=max(a, b)){
    if(i%a==0 && i%b==0){
      return i;
    }
  }
}

int main(){
  long long int a, b;
  while(cin >> a >> b){
    //    cout << a << " " << b <<endl;
    //    int GCD = find_GCD(a, b);
    //    cout << GCD << endl;
    //    cout << find_GCD(a, b) << endl;
    //    long long int GCD = find_GCD(a, b);
    //    long long int LCM = a*b/GCD;

    long long int GCD;
    long long int LCM;
    LCM = find_LCM(a, b);
    GCD = a*b/LCM;
    cout << GCD << " " << LCM << endl;
  }

} 