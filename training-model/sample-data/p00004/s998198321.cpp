#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  double a, b, c, d, e, f;
  while ((cin >> a >> b >> c >> d >> e >> f)) {
    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    c /= a;
    b /= a;
    a = 1.0;
    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    double tmp = d / a;
    // cout << "tmp " << tmp << endl;
    d -= a * tmp;
    e -= b * tmp;
    f -= c * tmp;
    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    f /= e;
    e = 1.0;
    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    tmp = b / e;
    // if (b * e >= 0) {
    b -= e * tmp;
    c -= f * tmp;
    /*} else {
      b += e * tmp;
      c += f * tmp;
      }*/
    // cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
    // cout << setprecision(4) << c << " " << setprecision(4) << f << endl;
    printf("%2.3f %2.3f\n", c, f);
  }
  return 0;
}