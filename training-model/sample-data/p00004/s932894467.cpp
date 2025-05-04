//#define __USE_MINGW_ANSI_STDIO 0
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define INF (1LL<<30)
#define LLINF (1LL<<60)
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

signed main(void)
{
	double a, b, c, d, e, f, x, y;
	while(cin >> a >> b >> c >> d >> e >> f) {
		//cout << c*e-b*f << " " << a*e-b*d << " " << c*d-a*f << " " << b*d-a*e << endl;
		if(c*e==b*f) x = 0;
		else x = (c*e-b*f)/(a*e-b*d);
		if(c*d==a*f) y = 0;
		else y = (a*f-c*d)/(a*e-b*d);
		printf("%.3f %.3f\n", x, y);
	}
	return 0;
}