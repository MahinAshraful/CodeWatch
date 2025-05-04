#include<bits/stdc++.h>
#define loop(i, a, b) for(int i = a; i < b; i++) 
#define rep(i, a) loop(i, 0, a)
using namespace std;
const int MOD = 1000000007;
const int inf = 1e8;
using vi = vector <int>;
using vvi = vector <vi>;
using vc = vector <char>;
using vvc = vector <vc>;
using vs = vector <string>;
using vvs = vector <vs>;
//g++ -std==c++14
//setprecision(10)
int n;

int main(){
    cin >> n;
    long long va = 100000;
    rep(i, n){
        va *= 1.05;
        if(0 < va - (va / 1000 * 1000) && va - (va / 1000 * 1000) < 1000)
            va = va / 1000 * 1000 + 1000;
    }
    cout << va << endl;
}