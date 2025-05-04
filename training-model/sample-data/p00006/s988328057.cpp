#include <iostream>
using namespace std;

int main(void){
  string a;
  cin >> a;

  for(int i = a.length() - 1;0<=i;i--) cout << a.at(i);
  cout << endl;

  return 0;
}