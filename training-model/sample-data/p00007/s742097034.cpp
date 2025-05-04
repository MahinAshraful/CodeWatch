#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1e9;
int MOD = 1e9+7;
main(){
    int N;
    int debt = 100000;
    cin >> N;
    for(int i = 0;i < N;i++){
        debt *= 1.05;
        debt = (debt+999)/1000*1000;
    }
    cout << debt << endl;
}