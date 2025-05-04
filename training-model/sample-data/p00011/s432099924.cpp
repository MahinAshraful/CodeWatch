// 0011.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include<stdio.h>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <map>     
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <iomanip>
#include <stack>
#include <string>
#include <vector>
#include <typeinfo>
using namespace std;
#define ll long long
#define ld long double
#define roop(a,t) for(ll a=0;a<t;a++)
int main()
{
	ll w, n;

	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> w >> n;
	ll a[32];
	roop(i, 32) {
		a[i] = i + 1;
	}
	roop(i, n) {
		int swap[2]; char kanma;
		cin >> swap[0] >> kanma >> swap[1];
		ll before = a[swap[0] - 1];
		a[swap[0] - 1] = a[swap[1] - 1];
		a[swap[1] - 1] = before;
	}
	roop(i, n) {
		cout << a[i] << endl;
	}
	return 0;
}
