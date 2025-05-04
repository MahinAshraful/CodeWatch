#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int week;
    cin >> week;

    double debt = 100;    // * 1000 yen
    while (week--) {
        debt = ceil(debt * 1.05);
    }

    cout << fixed << setprecision(0)
         << (debt * 1000) << endl;

    return 0;
}