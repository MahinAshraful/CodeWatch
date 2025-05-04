#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep(i, n) REP (i, 0, n)
#define mset(a, n) memset(a, n, sizeof(a))

using namespace std;

const int MAX_N = 1000000;
bool prime[MAX_N];
void eratos() {
	rep(i, MAX_N) prime[i] = true;
	prime[0] = false;
	prime[1] = false;
	REP(i, 2, sqrt(MAX_N)) {
		if (prime[i]) {
			for (int j = 0; i * (j + 2) < MAX_N; ++j) {
				prime[i * (j + 2)] = false;
			}
		}
	}
}

int main() {
	eratos();
	int n;
	while (cin >> n) {
		int ans = 0;
		for (int i = 2; i <= n; ++i) {
			if (prime[i]) ans++;
		}
		cout << ans << endl;
	}
}