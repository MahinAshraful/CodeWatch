#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;
typedef pair<int, int> P;

int prime[1000010];
bool is_prime[1000010];
void sieve(int n){
    int p = 0;
    for(int i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2*i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

signed main(){
    sieve(1000000);
    int n;
    while(cin >> n){
        int ans = 0;
        rep(i, 2, n + 1){
            if(is_prime[i]) ans++;
        }
        cout << ans << endl;
    }
}