#include <iostream>
#include <iomanip>

int main(void)
{
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  double a, b, c, d, e, f, x, y;
  while (std::cin >> a >> b >> c >> d >> e >> f) {
    x = (b * f - e * c) / (b * d - a * e);
    y = (c - a * x) / b;
    if (x == 0) x = 0;
    if (y == 0) y = 0;
    std::cout << std::fixed << std::setprecision(3) << x << " " << y << std::endl;
  }
}

