#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <cstdio>

int main(void)
{
  int w, n;

  std::cin >> w >> n;

  std::vector<int> base;
  for (int i = 0; i < w; i++) {
    base.push_back(i + 1);
  }

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d,%d", &a, &b);
    std::swap(base[a - 1], base[b - 1]);
  }

  for (int i = 0; i < w; i++) {
    std::cout << base[i] << std::endl;
  }

  return 0;
}