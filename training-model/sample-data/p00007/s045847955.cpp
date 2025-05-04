#include <cstdio>

using namespace std;

long long roundup(long long *x){
  (*x) += 999;
  (*x) /= 1000;
  (*x) *= 1000;
}

long long addinterest(long long *x){
  (*x) *= 1.05;
  roundup(x);
}

int main()
{
  long long debt = 100000;
  int n;
  scanf("%d", &n);
  while(n--)
    addinterest(&debt);

  printf("%lld\n", debt);
  return 0;
}