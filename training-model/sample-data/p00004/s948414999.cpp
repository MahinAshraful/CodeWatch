#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  double a, b, c, d, e, f;
  while(cin >> a >> b >> c >> d >> e >> f){
    double bb = b * d, cc = c * d;
    double ee = e * a, ff = f * a;
    double y = (cc - ff) / (bb - ee);
    double x = (c - b * y) / a;

    printf("%0.3f %0.3f\n", x, y);
  }
  return 0;
}

