#include <cstdio>
using namespace std;

int main() {
  double a, b, c, d, e, f;
  while (~scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f)) {
    double y = (c * d - a * f) / (b * d - a * e);
    double x = (c - b * y) / a;
    printf("%.3lf %.3lf\n", x, y);
  }
}
