#include <cstdio>
using namespace std;
int w, n, a[31], f, s, t;
int main() {
  for (int i = 0; i < 31; i++) {
    a[i] = i;
  }
  scanf("%d%d", &w, &n);
  for (int i = 0; i < n; i++) {
    scanf("%d,%d", &f, &s);
    t = a[f];
    a[f] = a[s];
    a[s] = t;
  }
  for (int i = 1; i <= w; i++) {
    printf("%d\n", a[i]);
  }
}
