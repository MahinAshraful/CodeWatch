#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f) {
        double y = ((d*c-a*f) / (double)(b*d-a*e));
        double x = (c - b*y) / (double)a;
        printf("%.3f %.3f\n", x, y);
    }
    return(0);
}