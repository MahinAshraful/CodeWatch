#include <stdio.h>
#include <cmath>
using namespace std;

int main(void) {
  float a, b, c, d, e, f;
  while (scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f)+1)  {
    float x = (c*e-b*f)/(a*e-b*d);
    float y = (c*d-a*f)/(b*d-a*e);
    if (abs(x) <= 1.0e-4) x = 0.0;
    if (abs(y) <= 1.0e-4) y = 0.0;
    printf("%.3f %.3f\n", x, y);
  }
  return 0;
}