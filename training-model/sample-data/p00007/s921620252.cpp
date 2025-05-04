#include <iostream>
using namespace std;

int main()
{
 int m = 100000;
 int w;

 cin >> w;

 for(int i=0; i<w; i++){
  m *= 1.05;
  m += 999;
  m /= 1000;
  m *= 1000;
 }

 cout << m << '\n';

 return 0;
}