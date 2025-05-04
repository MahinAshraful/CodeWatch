#include <iostream>
using namespace std;

int main(){
  int n, debt=100000;
  cin >> n;

  while(n--){
    debt = debt*105/100;
    if(debt % 1000 != 0)
      debt+=1000;
    debt /= 1000;
    debt *= 1000;
  }
  cout << debt << endl;
  return 0;
}