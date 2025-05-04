#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

const double interest = 0.05;

int weeklyAdd(int debt) {
  debt = debt * (1 + interest);
  if (debt % 1000 != 0)
    debt = (debt / 1000 + 1) * 1000;
  // std::cout << debt << '\n';
  return debt;
}

int main(int argc, char const *argv[]) {
  // int week = 5;
  int week;
  std::cin >> week;
  int debt = 100000;

  for (size_t i = 0; i < week; i++) {
    debt = weeklyAdd(debt);
  }
  std::cout << debt << '\n';

  return 0;
}

