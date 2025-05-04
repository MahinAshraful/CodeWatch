#include <iostream>
#include <iomanip>
using namespace std;
int main() {
  double a,b,c,d,e,f;
  double x, y;
  while(cin >> a >> b >> c >> d >> e >> f) {
    x = (c*e-b*f)/(a*e-b*d) + 0;
    y = (a*f-c*d)/(a*e-b*d) + 0;
    cout << fixed << setprecision(3) << x << " " <<  y << endl;
  }
}