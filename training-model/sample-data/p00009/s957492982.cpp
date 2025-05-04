#include<iostream>
using namespace std;
 
static const int MAX = 1000000;

int main() {
    static bool is_prime[MAX] = { false };
    static int npr[MAX];
    for (int i = 2; i<MAX; i++) {
        if (!is_prime[i]) {
            for (int j = 2; j*i<MAX; j++) {
                is_prime[i*j] = true;
            }
        }
        npr[i] = npr[i - 1] + !is_prime[i];
    }
    int n;
    while (cin >> n) {
        cout << npr[n] << endl;
    }
    return 0;
}