#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int num; cin >> num;
    for(int r = 0; r <  num; r++) {
        int a, b, c; cin >> a >> b >> c;
        if(a*a + b*b == c*c || b*b + c*c == a*a || c*c + a*a == b*b)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return(0);
}