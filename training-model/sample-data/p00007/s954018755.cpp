#include <bits/stdc++.h>
using namespace std;
long money = 100000;
void up() {
    int judge = money % 1000;
    //cout << judge << endl;
    if(judge) {
        money -= judge; money += 1000;
    }
}

int main(void) {
    int n; cin >> n;
    for(int r = 0; r < n; r++) {
        money *= 1.05; up();
    }
    cout << money << endl;
    return(0);
}