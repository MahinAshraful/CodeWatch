#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define ISEQ(c) (c).begin(), (c).end()
typedef long long ll;

int main() {
  int w, n;
  cin >> w >> n;
  int c[w];
  for (int i = 1; i <= w; i++)
    c[i-1] = i;

  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d,%d", &a, &b);
    swap(c[a-1], c[b-1]);
  }

  for (int i = 0; i < w; i++)
    cout << c[i] << endl;
}