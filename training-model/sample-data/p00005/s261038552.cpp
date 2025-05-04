#include <iostream>
using namespace std;

int euclide(int m, int n)
{
  int tmp;
  if(n == 0)
    return m;
  tmp = n;
  n = m % n;
  m = tmp;
  euclide(m, n);
}

int main()
{
  int a, b;
  while(cin >> a >> b){
    if(a < b){
      int tmp = a;
      a = b;
      b = tmp;
    }
    int gcd = euclide(a, b);
    cout << gcd << ' ' << a * (b / gcd) << endl;
  }
}
    