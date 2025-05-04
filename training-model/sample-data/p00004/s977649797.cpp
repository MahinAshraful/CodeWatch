#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
  double a, b, c, d, e, f;
  cout << fixed;
  cout << setprecision(3);
  
  while(cin >> a >> b >> c >> d >> e >> f) {
    double x = (b * f - c * e) / (b * d - a * e);
    double y = (d * c - a * f) / (b * d - a * e);
    
    x += 0;
    y += 0;
    cout << x << " " << y << endl;
  }
}