#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <time.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define SQR(X) ((X)*(X))


int test = 0;
/* ここからが本編 */
int main(void)
{
  int i,j,k,l;
  int n;
  int w;
  int e[50];
  cin >> w;
  cin >> n;
  rep(i,w+1) {
    e[i] = i;
  }
  rep(i,n) {
    int a,b;
    char c;
    cin >> a >> c >> b;
    swap(e[a],e[b]);
  }
  REP(i,1,w+1) {
    cout << e[i] << endl;
  }
  return 0;
}