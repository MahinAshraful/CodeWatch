#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

constexpr int LIM = 1000000;

static char isprime[LIM];
static int numofprime[LIM];

void setprime(int N) {
    fill(isprime, isprime + N + 1, 1);
    isprime[0] = isprime[1] = 0;
    for(int x = 2, lim = (int)sqrt(N); x <= lim; ++x) {
        if(isprime[x]) {
            for(int y = x * x; y <= N; y += x) {
                isprime[y] = 0;
            }
        }
    }
    numofprime[0] = 0;
    for(int x = 0; x < N; ++x) {
        numofprime[x + 1] = numofprime[x] + isprime[x + 1];
    }
}

int main() {
    setprime(999999);
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", numofprime[n]);
    }
    return 0;
}