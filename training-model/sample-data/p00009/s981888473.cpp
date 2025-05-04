#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <numeric>
#include <sstream>

#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define REP2(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1;i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define PI 3.14159265358979

using namespace std;

//================================================
vector<int>prime(1000000);
vector<bool>is_prime(1000001);

//Sieve of Eratosthenes
int func(int N) {
	int p = 0;

	REP(i, N + 1) is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	REP2(i, 2, N + 1) {
		if (is_prime[i]) {
			prime[p++];
			for (int j = 2 * i; j <= N; j += i) is_prime[j] = false;
		}
	}
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	while (cin >> N) {
		cout << func(N) << "\n";
	}
	return 0;
}