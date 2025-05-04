#include<iostream>
#include<cmath>
 
using namespace std;
 
double round(double source, int precision) {    // ?????¨?????\
    return floor((fabs(source) * pow(10, (double)precision) + 0.5)) / pow(10, (double)precision) * (source < 0 ? -1 : 1);
}
 
int main() {
    double a, b, c, d, e, f, x, y;
 
    while (cin >> a >> b >> c >> d >> e >> f) {
        x = (c * e - b * f) / (a * e - b * d);
        y = (a * f - c * d) / (a * e - b * d);
 
        cout.precision(3);
        cout << fixed << round(x, 3) << " " << round(y, 3) << endl;
        //cout << fixed << x + 1e-10 << " " << y + 1e-10 << endl;
    }
 
    return 0;
}