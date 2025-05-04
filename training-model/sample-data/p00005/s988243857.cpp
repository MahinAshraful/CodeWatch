#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <stdint.h>
using namespace std;

template <class T>
T gcd(const T &a, const T &b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}

template <class T>
T lcm(const T &a, const T &b)
{
  T g = gcd(a, b);
  return a / g * b;
}

int main()
{
  for (int64_t a, b; cin >> a >> b; ) {
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
  }
  return 0;
}