// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
template<typename V> constexpr typename V::value_type sum(const V &v) { return accumulate(all(v), 0); }
void solve();
main { solve(); return 0; }
// clang-format on

pair<double, double> cramer(double a1, double a2, double b1, double b2, double c1, double c2) {
  double d   = a1 * b2 - b1 * a2;
  double nx1 = c1 * b2 - b1 * c2;
  double nx2 = a1 * c2 - c1 * a2;
  return mp(nx1 / d, nx2 / d);
}

double g(double x) {
  return double((int) (x * 1000)) / 1000;
}

void solve() {
  int a, b, c, d, e, f;
  while (cin >> a >> b >> c >> d >> e >> f) {
    pair<double, double> p = cramer(a, d, b, e, c, f);
    cout << prec(3) << g(p.first) << ' ' << g(p.second) << endl;
  }
}