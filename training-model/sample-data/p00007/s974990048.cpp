#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, a = 100000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = static_cast<int>(ceil(a * 0.00105)) * 1000;
    }
    cout << a << endl;
    return 0;
}