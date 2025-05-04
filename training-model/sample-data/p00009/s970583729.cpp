#include <iostream>
using namespace std;

int prime(int n) {
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i <= n / i; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {

    int C[1000000] = {0};
    for (int i = 2; i < 1000000; ++i) {
        C[i] = prime(i);
    }
    for (int i = 2; i < 1000000; ++i) {
        C[i] += C[i - 1];
    }

    int n;
    while (cin >> n) {
        cout << C[n] << endl;
    }

    return 0;
}