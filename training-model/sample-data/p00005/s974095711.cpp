#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
ll gcd( ll a, ll b ) {
  if ( b == 0 ) return a;
  return gcd( b, a % b );
}
 
int main() {
  ll a,b;
  while ( cin >> a >> b ) {
  ll ans = gcd(a,b);
  ll ans2 = a * b / ans;
  cout << ans << " " << ans2 << endl;
  }
  return 0;
}