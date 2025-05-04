#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
using namespace std;

#define REP(i,n) for(int i=0; i<n; i++)
#define RPA(i,s,e) for(int i=s; i<=e; i++)
#define RPD(i,s,e) for(int i=s; i>=e; i--)
#define PB(a) push_back(a)
#define MP(i,s) make_pair(i,s)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define PRT(a) cout << (a) << endl
#define PRT2(a,b) cout << (a) << " " << (b) << endl
#define PRT3(a,b,c) cout << (a) << " " << (b) << " " << (c) << endl

typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> P;


void coding() {
	vector<int> v(5);
	for(int i=0; i<5; i++) {
		cin>>v[i];
	}
	sort(ALL(v), greater<int>());
	for(int i=0; i<5; i++) {
		printf("%d%c", v[i], i==4 ? '\n' : ' ');
	}
}

// #define _LOCAL_TEST

int main() {
#ifdef _LOCAL_TEST
	clock_t startTime = clock();
	freopen("a.in", "r", stdin);
#endif

	coding();

#ifdef _LOCAL_TEST
	clock_t elapsedTime = clock() - startTime;
	cout << endl;
	cout << (elapsedTime / 1000.0) << " sec elapsed." << endl;
	cout << "This is local test" << endl;
	cout << "Do not forget to comment out _LOCAL_TEST" << endl << endl;
#endif
}