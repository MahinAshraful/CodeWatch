#include <iostream>
using namespace std;

unsigned int gcd(unsigned int a, unsigned int b)
{
  if (b == 0)
    return a;
  else
    gcd(b, a % b);
}

int main()
{
  unsigned int a, b;


  while (cin >> a >> b)
  {
    if (a < b)
    {
      int t = a;
      a = b;
      b = t;
    }

    int g = gcd(a,b);
    int l = a * (b / g);

    cout << g << ' ' << l << endl;
  }
  return 0;
}