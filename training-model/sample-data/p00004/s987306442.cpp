#include <iostream>
#include <cstdio>
using namespace std;

inline void swap(int &a, int &b) { int t = a; a = b; b = t; }

int main()
{
  int a, b, c, d, e, f;
  
  while (cin >> a >> b >> c >> d >> e >> f)
  {
    int det = a*e-b*d;
    int x = e*c - b*f;
    int y = a*f - d*c;
    
    double xx = 0, yy = 0;
    if (x != 0) xx = (double)x/det;
    if (y != 0) yy = (double)y/det;
    printf("%.3f %.3f\n", xx, yy);
  }
  return 0;
}