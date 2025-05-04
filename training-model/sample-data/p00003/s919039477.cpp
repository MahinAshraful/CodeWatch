#include <iostream>

using namespace std;

bool isRight(int a, int b, int c) {
    return a * a + b * b == c * c;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (isRight(a, b, c) || isRight(b, c, a) || isRight(c, a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}