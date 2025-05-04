#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double a, b, c, d, e, f;
    double x, y;

    while (cin >> a >> b >> c >> d >> e >> f)
    {
//        cout << "input numbers: " << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;

        y = (a*f - d*c) / (a*e - d*b);
        x = (c - b*y) / a;

//        cout << "before round: " << std::fixed << std::setprecision(4) << x << " " << y << endl;

        x = x * 1000.0;
        y = y * 1000.0;

        x = round(x);
        y = round(y);

        x = x / 1000.0;
        y = y / 1000.0;

//        cout << "after round: " << std::fixed << std::setprecision(4) << x << " " << y << endl;

        cout << std::fixed << std::setprecision(3) << x << " " << y << endl;
    }

    return 0;
}

