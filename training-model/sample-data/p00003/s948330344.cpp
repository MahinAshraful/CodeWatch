#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int times;
    cin >> times;

    for (int i = 0;i < times; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        double a2, b2, c2;
        a2 = pow(a,2);
        b2 = pow(b,2);
        c2 = pow(c,2);

        if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == a2 + b2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}