#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

using namespace std;
string is_valid_triangle(int a, int b, int c){
    string out = "NO";
    if (pow(a, 2) == pow(b,2) + pow(c,2) || pow(b, 2) == pow(a, 2) + pow(c, 2) || pow(c, 2) == pow(a, 2) + pow(b, 2)){
        out = "YES";
    }
    return out;
}
int main() {
    int l;
    cin >> l;
    REP(i, 0, l){
        int a, b, c;
        cin >> a >> b >> c;
        cout << is_valid_triangle(a, b, c) << endl;
    }
    return 0;
}