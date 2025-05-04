#include <bits/stdc++.h>

int main() {

  std::vector<int> v;
  int w;
  int n;
  int a, b;

  std::cin >> w;
  for(int i = 1; i <= w; ++i) {
    v.push_back(i);
  }

  std::cin >> n;
  for(int i = 0; i < n; ++i) {
    scanf("%d,%d", &a, &b);
    std::swap(v[a-1], v[b-1]);
  }

  for(int i = 0; i < w; ++i) {
    std::cout << v[i] << std::endl;
  }
    
  return 0;
}