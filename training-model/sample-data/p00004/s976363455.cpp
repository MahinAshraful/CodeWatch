#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

double a, b, c, d, e, f;
void solve(double &x, double &y)
{
    if (b == 0)
    {
        x = c / a;
        y = (f - d * x) / e;
    }
    else
    {
        x = (b * f - e * c) / (b * d - e * a);
        y = (c - a * x) / b;
    }
}

int main()
{
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        double x, y;
        solve(x, y);
        if (x == 0) x = 0;
        if (y == 0) y = 0;
        printf("%.3f %.3f\n", x, y);
    }
    return 0;
}