/*
*AOJ0009: Prime Number
**問題
[http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009&lang=jp:title]
**解法
エラトステネスのふるい。
*/
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
const int N = 1000000;

int main() {
  // エラトステネスのふるいを作成
  bool isPrime[N]; // ふるい
  int cntPrime[N]; // n個以下の素数の個数
  for (int i = 0; i < N; i++)
    isPrime[i] = true;
  isPrime[0] = false; isPrime[1] = false;
  cntPrime[0] = 0;
  for (int i = 1; i < N; i++) {
    if (isPrime[i]) {
      cntPrime[i] = cntPrime[i-1] + 1;
      for (int j = 2 * i; j < N; j += i)
        isPrime[j] = false;
    } else {
      cntPrime[i] = cntPrime[i - 1];
    }
  }

  // 入力と出力
  int n;
  while (cin >> n) {
    cout << cntPrime[n] << endl;
  }

}