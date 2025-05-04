#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int num;
    cin >> num;
    for(int r = 0; r < num; r++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b){ a ^= b; b ^= a; a ^= b;}
        if(a > c){ a ^= c; c ^= a; a ^= c;}
        if(b > c){ b ^= c; c ^= b; b ^= c;}
        if(a * a + b * b == c * c) printf("YES\n");
        else printf("NO\n");
    }
    
    return(0);
}