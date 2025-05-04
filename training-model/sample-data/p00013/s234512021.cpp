#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int a;
    stack<int> s;
    while(cin >> a){
        if(a)s.push(a);
        else{
            cout << s.top() << endl;
            s.pop();
        }
    }
}