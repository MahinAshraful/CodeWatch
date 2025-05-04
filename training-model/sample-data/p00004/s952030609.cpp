#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {
    double a, b, c, d, e, f;
    while(cin >> a) {
        cin >> b >> c >> d >> e >> f;
        double x = (c * e - b * f) / (a * e - b * d);
        double y = (-c * d + a * f) / (a * e - b * d);
        if (abs(x) < 1e-3) x = 0.0;
        if (abs(y) < 1e-3) y = 0.0;
        cout << fixed << setprecision(3) << x << " " << y << endl;
    }
    return 0;
}