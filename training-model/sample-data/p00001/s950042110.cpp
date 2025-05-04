#include <iostream>
#include <algorithm>
using namespace std;

int des(int x, int y) {
  return x > y;
}

int main() {
  int a[10];
  for (int i=0; i<10; i++) {
    cin >> a[i];
  }
  //sort(a, a+10, [](const int& x, const int& y) {return x > y;});
  sort(a, a+10, des);
  for (int i=0; i<3; i++) {
    cout << a[i] << endl;
  }
}